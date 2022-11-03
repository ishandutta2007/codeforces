import Control.Applicative
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
	_ <- readLn :: IO Int
	w <- map fst . mapMaybe BS.readInt . BS.words <$> BS.getLine
	putStrLn . show $ solve w

solve :: [Int] -> Int
solve w = f 0 0 . elems $ arr
	where
		arr					= accumArray (+) 0 (0, 100 + 10 ^ 6) $ [(x, 1) | x <- w] :: UArray Int Int
		f ans _ []			= ans
		f ans k (x : xs)	= f (ans + ((k + x) `mod` 2)) ((k + x) `div` 2) xs