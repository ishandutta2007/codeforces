import Control.Applicative
import Control.Monad
import Data.List
main :: IO ()
main = do
	void getLine
	ns <- (map read . words <$> getLine) :: IO [Int]
	putStrLn . unwords . map show $ sort ns