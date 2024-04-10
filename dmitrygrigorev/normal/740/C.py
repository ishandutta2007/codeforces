n, m = list(map(int, input().split()))
minimum = 10000000000
for i in range(m):
    a, b = list(map(int, input().split()))
    if (b - a + 1) < minimum:
        minimum = b - a + 1
now = 0
line = []
for i in range(n):
    line += [now]
    now += 1
    if now >= minimum:
        now = 0
print(minimum)
print(" ".join(map(str, line)))