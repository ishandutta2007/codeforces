import Control.Applicative
import Data.List

main = interact $ show . (+ 1) . maximum . (0 :) . map length . filter (id . head) . group . (zipWith (<) <$> id <*> tail) . map (read :: String -> Int) . tail . words