import Control.Applicative
import Control.Monad

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
          print $ solve n m

solve:: Int -> Int -> Int
solve 1 _ = 1
solve n m | (n-m) <= (m-1) = m-1
          | otherwise      = m+1