import Control.Arrow
import Control.Applicative
import qualified Data.Map as M

main :: IO ()
main = getContents >>= print . solve . map read . tail . words

solve :: [Integer] -> Integer
solve =
    sum
    . (
        zipWith3
        (\i v (s, m) -> v * i - s + sum [i * M.findWithDefault 0 (v + i) m | i <- [1, -1]])
        [0 ..]
        <*> scanl (flip $ \x -> (x +) *** (M.insertWith (+) x 1)) (0, M.empty)
    )