import Control.Applicative
import Data.Char
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main = do
    s <- takeWhile (not . isSpace) . BS.unpack <$> BS.getLine
    putStrLn . fromMaybe "Impossible" . fmap show $ solve s []

solve [] [] = Just 0
solve [] _  = Nothing
solve (c : s) toClose
    | elem c "([{<" = solve s $ matching c : toClose
    | otherwise     = case toClose of
        []      -> Nothing
        x : xs  -> let sol = solve s xs in if x == c then sol else (+ 1) <$> sol

matching c = case c of
    '(' -> ')'
    '[' -> ']'
    '{' -> '}'
    '<' -> '>'
    _   -> error ""