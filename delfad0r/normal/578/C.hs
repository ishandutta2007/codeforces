import Data.Function (on)
import Data.Time.Clock
import Data.Maybe (fromJust)
import qualified Data.ByteString.Lazy.Char8 as ByteString

main = do
	tbegin <- getCurrentTime
	input <- ByteString.getContents
	let xs = map (fromIntegral . fst . fromJust . ByteString.readInt) . tail . ByteString.words $ input
	solve tbegin xs (minimum xs) (maximum xs)

solve :: UTCTime -> [Double] -> Double -> Double -> IO ()
solve tbegin xs lo hi = do
	tcurrent <- getCurrentTime
	if (diffUTCTime tcurrent tbegin) > 0.8
	then do
		putStrLn . show . maxSum $ xs'
	else do
		if ((<) `on` maxSum) xs' (map negate xs')
		then solve tbegin xs lo mid
		else solve tbegin xs mid hi
	where
		mid = (lo + hi) / 2
		xs' = map (subtract mid) xs
		maxSum l = maxSum' (head l) 0 l
		maxSum' m pref []		= max m pref
		maxSum' m pref (a:as)	= maxSum' (max m pref) ((max 0 pref) + a) as