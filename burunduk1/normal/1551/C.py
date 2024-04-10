def solve():
	n = int(input())
	words = [input() for i in range(n)]
	ans = 0
	for ch in 'abcde':
		cnt = sorted([2*word.count(ch)-len(word) for word in words])
		# print(ch, cnt)
		balance, res = 0, 0
		for k in cnt[::-1]:
			balance += k
			res += 1
			if balance <= 0: res -= 1; break
		ans = max(ans, res)
	print(ans)

t = int(input())
for _ in range(t): solve()