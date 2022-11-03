import Control.Applicative
import Control.Arrow
import Data.Function
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
	(n : _ : input) <- map fst . mapMaybe BS.readInt . BS.words <$> BS.getContents
	let (as, bs) = (first sort) . (second $ (sort . (flip zip) [0 ..])) $ splitAt n input
	putStrLn $ concatMap (($ " ") . (shows . fst)) $ sortBy (compare `on` snd) $ scanl1 (\(acc, _) (v, i) -> (acc + v, i)) $ f as bs

f _ [] 				= []
f [] bs				= map (first $ const 0) bs
f as ((b, i) : bs)	= let (smaller, larger) = span (<= b) as in (length smaller, i) : f larger bs