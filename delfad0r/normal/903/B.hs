import Control.Applicative

main :: IO ()
main = do
    [h1, a1, c1, h2, a2] <- map read . words <$> getContents
    let s = ((h2 - 1) `div` a1) + 1;
        h = head [t | t <- [0 ..], h1 + t * c1 > (t + s - 1) * a2]
    print $ s + h
    putStr . unlines $ replicate h "HEAL" ++ replicate s "STRIKE"