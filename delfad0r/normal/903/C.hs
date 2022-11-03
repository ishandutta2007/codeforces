import Data.List

main :: IO ()
main =
    interact
    $ show
    . maximum
    . map length
    . group
    . sort
    . map (read :: String -> Int)
    . tail
    . words