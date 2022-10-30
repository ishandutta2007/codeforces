import Data.List

seconds :: [a] -> [a]
seconds [] = []
seconds [x] = [x]
seconds (x:_:xs) = x : seconds xs

main :: IO ()
main = fmap (intersperse '+' . sort . seconds) getLine >>= putStrLn