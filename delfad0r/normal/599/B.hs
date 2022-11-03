import Control.Applicative
import Data.Array.IArray
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
    (n : _ : rest) <- map fst . mapMaybe BS.readInt . BS.words <$> BS.getContents
    let (f, b) = splitAt n rest
    let invf = accumArray (flip (:)) [] (1, n) $ zip f [1 ..]
    either putStrLn ((putStrLn "Possible" >>) . putStrLn . concat . intersperse " " . map show) $ solve b invf

solve :: [Int] -> Array Int [Int] -> Either String [Int]
solve [] _ = Right []
solve (b : bs) invf =
    case invf ! b of
        [a] -> solve bs invf >>= Right . (a :)
        []  -> Left "Impossible"
        _   -> solve bs invf >> Left "Ambiguity"