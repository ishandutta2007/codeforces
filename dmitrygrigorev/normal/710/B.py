n = int(input())
line = sorted(list(map(int, input().split())))
a = 0
for i in range(1, n):
    a += (line[i] - line[0])
ind = line[0]
rasst = a
for i in range(1, n):
    r = abs(line[i] - line[i - 1])
    a1 = a - (n - i - 1) * r + (i - 1) * r
    if a1 < rasst:
        rasst = a1
        ind = line[i]
    a = a1
print(ind)