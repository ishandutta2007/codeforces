import Control.Arrow
import Data.Char
import Data.List

main = interact $ f . mySplit . filter (/= '\n')

mySplit [] = [[]]
mySplit s = let (x, y) = span (\c -> c /= ',' && c /= ';') s in if null y then [x] else x : mySplit (tail y)
	
f ws = let (w1, w2) = partition (\s -> if null s then False else s == "0" || (head s /= '0' && all isDigit s)) ws in (g w1) ++ "\n" ++ (g w2)
g w = if null w then "-" else (show . concat $ intersperse "," w)