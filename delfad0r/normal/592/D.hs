import Control.Applicative
import Data.Array.IArray
import Data.Function
import Data.Maybe
import Data.Tuple
import qualified Data.ByteString.Char8 as BS

main = do
    (n : _ : input) <- map fst . mapMaybe BS.readInt . BS.words <$> BS.getContents
    let (edges, attacked) = (\(x, y) -> (empair x, y)) . splitAt (2 * n - 2) $ input
    let graph = accumArray (flip (:)) [] (1, n) (edges ++ (map swap edges)) :: Array Int [Int]
    let isAttacked = accumArray (||) False (1, n) . zip attacked . repeat $ True :: Array Int Bool
    let root = minimum attacked
    let maxPath = let u = dfsMaxPath graph isAttacked 0 $ root in max (fst . fst $ u, -root) $ snd u
    putStrLn . show $ - snd maxPath
    putStrLn . show $ (dfsTotal graph isAttacked 0 $ root) - fst maxPath

empair []           = []
empair (a : b : ls) = (a, b) : (empair ls)

max2 []         = ((0, minBound :: Int), (0, minBound :: Int))
max2 (x : xs)   = let (m1, m2) = max2 xs in if x > m1 then (x, m1) else (m1, max x m2)

dfsTotal graph isAttacked p n = sum . map f . filter (p /=) $ (graph ! n)
    where
        f x = let ans = dfsTotal graph isAttacked n x in if ans /= 0 || isAttacked ! x then ans + 2 else 0

dfsMaxPath graph isAttacked p n = f . filter (\((_, x), _) -> x /= 0) . map (dfsMaxPath graph isAttacked n) . filter (p /=) $ (graph ! n)
    where
        f []            = ((0, if isAttacked ! n then -n else 0), (0, -n))
        f [(v1, v2)]    = let ans1 = (fst v1 + 1, snd v1) in (ans1, max ans1 v2)
        f ls            = let (mp1, mp2) = max2 . map fst $ ls
                          in ((fst mp1 + 1, snd mp1), max (maximum . map snd $ ls) (fst mp1 + fst mp2 + 2, (max `on` snd) mp1 mp2))