-- @betaveros :: vim:set fdm=marker:
import Control.Applicative

inputRow :: (Read a) => IO [a]
inputRow = map read . words <$> getLine
inputInts = inputRow :: IO [Int]

main :: IO ()
main = do
    [a,b,c,d,e,f] <- inputInts
    print $ (a+b+c)^2 - a^2 - c^2 - e^2