import Data.List

main = do
    s <- getLine
    s <- getLine
    let a = sort (map read (words s)) :: [Int]
    print (min (last a - head (tail a)) (last (init a) - head a))