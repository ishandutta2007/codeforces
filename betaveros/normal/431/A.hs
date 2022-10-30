-- la la la no testing at all
import Data.List
import Data.Char
main :: IO ()
main = do
  xs <- fmap (map (read :: String -> Int) . words) getLine
  cs <- getLine
  print . sum . map ((xs !!) . subtract 1 . digitToInt) $ cs