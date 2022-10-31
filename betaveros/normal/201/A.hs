ans 1 = 1
ans 2 = 3
ans 3 = 5
ans 4 = 3
ans 5 = 3
ans s = head [2*k+1 | k <- [1..], s <= 2*k^2 + 2*k + 1]

main = interact $ (++ "\n") . show . ans . read