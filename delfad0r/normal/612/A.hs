import Control.Applicative
import Data.List
import Data.Maybe

main = do
    (n : p : q : _) <- map read . words <$> getLine
    s <- getLine
    putStrLn $ case listToMaybe [i | i <- [0, p .. n], (n - i) `mod` q == 0] of
        Nothing -> "-1"  
        Just i  -> let (s1, s2) = splitAt i s in decorate $ (splitEvery p s1) ++ (splitEvery q s2)
    where
        decorate l      = unlines $ (show $ length l) : l
        splitEvery x    = takeWhile (not . null) . unfoldr (Just . splitAt x)