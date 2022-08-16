perm = [5, 0, 2, 3, 1, 4]
n = int(input())
ans = 0
for i in range(len(perm)):
	ans = ans * 2 + ((n >> perm[i]) & 1)

print(ans)