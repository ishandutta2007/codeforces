import Control.Applicative
import Data.Array.IArray
import qualified Data.Foldable as F
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
    n <- readLn :: IO Int
    a <- map fst . mapMaybe BS.readInt . BS.words <$> BS.getLine
    let s = accumArray (+) 0 (1, 10 ^ 5)  [(x, toInteger x) | x <- a] :: Array Int Integer
    let maxA = maximum a
    let dp = array (0, maxA) ((0, 0) : (1, s ! 1) : [(i, max (dp ! (i - 1)) ((dp ! (i - 2) ) + s ! i)) | i <- [2 .. maxA]]) :: Array Int Integer
    putStrLn . show . F.foldl1 max $ dp