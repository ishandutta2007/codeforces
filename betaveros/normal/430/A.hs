-- @betaveros :: vim:set fdm=marker:
import Control.Monad
import Control.Applicative
import Data.List
import Data.Ord
main :: IO ()
main = void getLine >> unwords . map (show . fst) . sortBy (comparing snd) . zip (cycle [0,1]) . map fst . sortBy (comparing snd) . zip [0..] . map (read :: String -> Int) . words <$> getLine >>= putStrLn