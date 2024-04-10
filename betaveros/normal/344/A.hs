magnetGroups ts = 1 + (length $ filter (uncurry (/=)) $ zip ts (tail ts))
readNLines (ln:ls) = take (read ln) ls
main = interact $ (++ "\n") . show . magnetGroups . readNLines . lines