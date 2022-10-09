n = int(input())
m = 10 ** 5 + 1
                                     
a = list(map(int, input().split())) 

cnt = [0 for i in range(m)]
for i in range(n):
	cnt[a[i]] += 1

dp = [(i * cnt[i]) for i in range(m)]
for i in range(m):
	for j in range(i + 2, min(m, i + 5)):
		dp[j] = max(dp[j], dp[i] + j * cnt[j])

print(max(dp))