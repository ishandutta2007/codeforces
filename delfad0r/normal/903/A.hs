main :: IO ()
main =
    interact
    $ unlines
    . map
        ((["NO", "YES"] !!)
        . fromEnum
        . (`elem` [3 * a + 7 * b | a <- [0 .. 100], b <- [0 .. 100]])
        . read
        )
    . tail
    . words