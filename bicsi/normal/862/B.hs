import           Control.Applicative
import           Control.Arrow
import           Control.Monad
import           Data.Array          (Array, (!))
import qualified Data.Array          as Array
import           Data.Function       (on)
import           Data.List           (foldl', groupBy, sortBy)
import           Data.Ord            (comparing)
import           System.IO


type Graph = Array Int [Int]

buildGraph :: Int -> [(Int, Int)] -> Graph
buildGraph n = Array.accumArray
    (flip (:)) ([] :: [Int]) (0, n - 1)

dfs :: Int -> Int -> Graph -> Int -> Int
dfs par col g node =
    foldl' (+) col $
    map (dfs node (1 - col) g) $
    filter (/= par) (g ! node)

main :: IO ()
main = do
    hSetBuffering stdin $ BlockBuffering (Just (2 ^ 15))
    n <- fmap (read :: String -> Int) getLine
    edgeList <- fmap concat $ replicateM (n - 1) $ fmap (\line ->
        let [a, b] = map (read :: String -> Int) $ words line in
        [(a - 1, b - 1), (b - 1, a - 1)]) getLine
    let graph = buildGraph n edgeList
    let a = dfs (-1) 0 graph 0

    let aLL = fromIntegral a :: Integer
    let nLL = fromIntegral n :: Integer
    print (aLL * (nLL - aLL) - nLL + 1)