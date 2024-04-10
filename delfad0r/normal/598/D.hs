import Control.Applicative
import Control.Arrow
import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array.Unboxed
import Data.List
import Data.Maybe
import Data.STRef
import qualified Data.ByteString.Lazy.Char8 as BS

main = do
    (strN : strM : _ : rest) <- BS.words <$> BS.getContents
    let (Just (n, _), Just (m, _)) = (BS.readInt strN, BS.readInt strM)
    let (t, qs) = ((arrayfy n m) *** (map fst . mapMaybe BS.readInt)) $ splitAt n rest
    let paintings :: UArray (Int, Int) Int
        paintings = accumArray (+) 0 ((1, 1), (n, m)) [((i, j), length . filter (t !) $ around n m (i, j)) | i <- [1 .. n], j <- [1 .. m]]
    let ans = runSTUArray $ do
        f <- newArray ((1, 1), (n, m)) (0, 0) :: ST s (STArray s (Int, Int) (Int, Int))
        v <- newArray ((1, 1), (n, m)) 0 :: ST s (STUArray s (Int, Int) Int)
        ans <- newArray ((1, 1), (n, m)) 0 :: ST s (STUArray s (Int, Int) Int)
        let emptyCells = [(i, j) | i <- [1 .. n], j <- [1 .. m], not $ t ! (i, j)]
        let find w = do
            myF <- readArray f w
            if myF == w
            then
                return w
            else do
                myF' <- find myF
                writeArray f w myF'
                return myF'
        let join u' w' = do
            u <- find u'
            w <- find w'
            when (u /= w) $ do
                writeArray f u w
                vu <- readArray v u
                vw <- readArray v w
                writeArray v w $ vu + vw
        forM_ emptyCells $ \w -> do
            writeArray f w w
            writeArray v w $ paintings ! w
        forM_ emptyCells $ \w@(i, j) -> do
            let up      = (i - 1, j)
                left    = (i, j - 1)
            when (i > 1 && not (t ! up)) $ join w up
            when (j > 1 && not (t ! left)) $ join w left
        forM_ emptyCells $ \w -> do
            myF <- find w
            myV <- readArray v myF
            writeArray ans w myV
        return ans
    BS.putStrLn . BS.unlines $ solve ans qs
        

arrayfy n m ls = array ((1, 1), (n, m)) [((i, j), c == '*') | (i, l) <- zip [1 ..] ls, (j, c) <- zip [1 ..] $ BS.unpack l] :: UArray (Int, Int) Bool

around n m (x, y) = filter (\(i, j) -> 0 < i && i <= n && 0 < j && j <= m) [(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)]

solve _ [] = []
solve ans (i : j : qs) = (BS.pack . show $ ans ! (i, j)) : solve ans qs