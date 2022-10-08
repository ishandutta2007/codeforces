# .............................
# ******....mn......***********
#       l           r
#       r 
# ...............**************
# l
# ********.....................r

for test in range(int(input())):
	n = int(input())
	stones = list(map(int, input().split()))
	n = len(stones)
	mn = stones.index(min(stones))
	mx = stones.index(max(stones))
	if mn > mx:
		mn, mx = mx, mn
	# .......*............*..........
	# xxxxxxxxxxxxxxxxxxxxx..........
	# .......xxxxxxxxxxxxxxxxxxxxxxxx
	# xxxxxxxx............xxxxxxxxxxx
	print(min(mx + 1, n - mn, mn + 1 + n - mx))

	# res = 0
	# for l in range(n):
	# 	for r in range(l, n+1):
	# 		if (not (l <= mn < r)) and (not (l <= mx < r)):
	# 			res = max(res, r - l)
	# print(n - res)