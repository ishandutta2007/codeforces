import Control.Applicative
import Control.Monad
import Data.Array
-----

--be carefull with the type inference

-----

---------
-- get space separated something

getListSp :: Read a => IO [a] 
getListSp = (map read . words) <$> getLine

---------



---------
-- output [a] in space separated form

putListSp :: Show a => [a]  -> IO()
putListSp ls = putStrLn $ show $ unwords $ map show ls

---------


--------
-- read an integer N, get N lines, make a list consist of them

getListLn :: Read a => IO [a]
getListLn = do n <- readLn
               s <- replicateM n getLine
	       return (map read s)
--------


main = do [n, m] <- getListSp
          votes <- replicateM m getListSp
	  print $ solve votes
	  
	  
solve :: [[Int]] -> Int
solve = maxInd . cntList . (map maxInd)

maxInd :: [Int] -> Int
maxInd xs = rval $ head $ filter ((== maxVal) . lval) $ zip xs [1..]
             where maxVal = foldl1 max xs
	           lval (x, y) = x
		   rval (x, y) = y

cntList :: [Int] -> [Int]
cntList xs = elems $ accumArray (+) 0 (1, maxVal) (zip xs (repeat 1))
              where maxVal = foldl1 max xs