n = int(input())
line = list(map(int, input().split()))
m1 = min(line)
m2 = max(line)
ans = 0
for i in range(len(line)):
    if line[i] < m2 and line[i] > m1:
        ans += 1
print(ans)