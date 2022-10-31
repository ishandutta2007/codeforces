import Data.List
import Data.Ord
import Control.Arrow
import Control.Applicative
import Control.Monad
main :: IO ()
main = sortBy (comparing snd) <$> replicateM 4 (second length . splitAt 2 . reverse . dropWhile (`elem` " \t\r\n") . reverse <$> getLine) >>= \choices -> putStrLn . pure $ case [fst (choices !! i) | (i,j,k) <- [(0,0,1),(3,2,3)], 2 * snd (choices !! j) <= snd (choices !! k)] of { [x] -> head x; _ -> 'C' }