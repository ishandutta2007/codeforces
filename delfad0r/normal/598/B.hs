import Control.Applicative
import Control.Arrow

main = do
    (str, queries) <- (head &&& (map read . drop 2)) . words <$> getContents
    putStrLn $ solve str queries

solve str [] = str
solve str (l : r : k : qs) = let str' = rotate str (l - 1) r k in solve str' qs

rotate str l r k
    | k >= r - l    = rotate str l r (k `mod` (r - l))
    | otherwise     = let ((pref, str'), suff) = first (splitAt l) $ splitAt r str in pref ++ ((shift str' k) ++ suff)

shift str k = uncurry (flip (++)) . splitAt ((length str) - k) $ str