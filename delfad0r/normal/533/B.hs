import Control.Applicative
import Data.Array.IArray
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
    n <- readLn 
    (ps, a) <- splitEveryTwo . map fst . mapMaybe BS.readInt . BS.words <$> BS.getContents
    let _ : edges = zip ps [1 ..]
    let graph = accumArray (flip (:)) [] (1, n) edges
    putStrLn . show . snd $ solve (listArray (1, n) (map toInteger a)) graph 1

splitEveryTwo [] = ([], [])
splitEveryTwo (x1 : x2 : xs) = let (l1, l2) = splitEveryTwo xs in (x1 : l1, x2 : l2)

solve :: Array Int Integer -> Array Int [Int] -> Int -> (Integer, Integer)
solve a graph n
	| null (graph ! n)	= (0, a ! n)
	| otherwise	= let
		l = map (solve a graph) (graph ! n)
		s = sum . map snd $ l
		minD = minimum [(snd x) - (fst x) | x <- l]
		in if odd . length $ l then (s - minD, s + (max 0 ((a ! n) - minD))) else (s, s + (a ! n))