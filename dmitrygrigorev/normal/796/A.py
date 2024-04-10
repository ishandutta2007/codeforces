n, m, k = list(map(int, input().split()))
m -= 1
line = list(map(int, input().split()))
answer = n
for i in range(n):
    if line[i] == 0:
        continue
    if line[i] > k:
        continue
    answer = min(answer, abs(m - i))
print(answer * 10)