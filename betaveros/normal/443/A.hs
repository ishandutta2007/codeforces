import Data.Char
import Data.List
main :: IO ()
main = fmap (length . nub . filter isAlpha) getLine >>= print