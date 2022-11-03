import Data.List

main = interact $ show . (+ 1) . foldl (\a x -> min (a + 1) x) 0 . sort . map read . tail . words