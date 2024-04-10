import Control.Applicative
import Data.Array.Unboxed
import Data.Char
import Data.Maybe
import Data.List
import qualified Data.ByteString.Char8 as BS

main = do
	str <- filter (not . isSpace) .  BS.unpack <$> BS.getContents
	let	freq :: UArray Char Int
		freq = accumArray (+) 0 ('a', 'z') [(c, 1) | c <- str]
	let toChange = map fst . filter (odd . snd) $ assocs freq;
		len = length toChange;
		new = [(c, 1) | c <- take (len `div` 2) toChange] ++ [(c, -1) | c <- take (len `div` 2) $ reverse toChange]
	let	freq' :: UArray Char Int
		freq' = accumArray (+) 0 ('a', 'z') $ (assocs freq) ++ new
	let newstr = concatMap (\(c, fr) -> replicate (fr `div` 2) c) $ assocs freq'
	putStrLn $ newstr ++ (maybe "" (return . fst) . find (odd . snd) $ assocs freq') ++ (reverse newstr)