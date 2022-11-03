import Control.Applicative
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
    f <- map snd . sort . (flip zip) [0 .. ] . tail . map fst . mapMaybe BS.readInt . BS.words <$> BS.getContents
    print . sum . map abs . zipWith (-) f $ tail f