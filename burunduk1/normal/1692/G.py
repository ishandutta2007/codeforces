import sys
input = sys.stdin.readline

def solve():
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	ans = 0
	cnt = 0
	for j in range(k):
		cnt += a[j] >= a[j + 1] * 2
	for i in range(n - k):
		ans += (cnt == 0)
		cnt -= a[i] >= a[i + 1] * 2
		if i + 1 + k < n:
			cnt += a[i + k] >= a[i + k + 1] * 2
	return ans

for _ in range(int(input())):
	print(solve())