ans :: [Integer] -> Integer
ans (x : (y : (z : xs))) = ((x + z - 1) `div` z) * ((y + z - 1) `div` z)

main = do
    d <- getLine
    putStr (show (ans (map read (words d))))