m, n = map(int, input().split())

answer = 0
for i in range(1, m + 1):
	answer += i * (pow((i / m), n) - pow(((i - 1) / m), n))

print(answer)