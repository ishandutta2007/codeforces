main = do
    s <- getLine
    let n = read s
    let l = round ((-1 + sqrt (fromIntegral (1 + 8 * n))) / 2)
    s <- getLine
    putStrLn (map (\y -> s !! y) (map (\x -> x * (x + 1) `div` 2) [0 .. l-1]))