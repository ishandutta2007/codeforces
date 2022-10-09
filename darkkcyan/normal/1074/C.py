from functools import partial
from itertools import combinations
from sys import stdin
n = int(stdin.readline())
a = [list(map(int, stdin.readline().split())) for i in range(n)]

def dis(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def dis3(a, b, c):
    return dis(a, b) + dis(b, c) + dis(c, a)

top = max(a, key=lambda u: u[1])
bot = min(a, key=lambda u: u[1])
left = min(a, key=lambda u: u[0])
right = max(a, key=lambda u: u[0])

ans3 = 0
for u, v in combinations([top, bot, left, right], 2):
    ans3 = max(ans3, max(map(partial(dis3, u, v), a)))

print(ans3, end=' ')
ans4 = dis(top, left) + dis(left, bot) + dis(bot, right) + dis(right, top)
print((str(ans4) + " ") * (n - 3))