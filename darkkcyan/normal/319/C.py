from collections import deque

class line:
    def __init__(self, k, b):
        self.k = k
        self.b = b

    def get(self, x):
        return self.k * x + self.b

def check(l1, l2, nl):
    return (nl.b - l2.b) * (l1.k - l2.k) - (nl.k - l2.k) * (l1.b - l2.b) <= 0

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0

hull = deque()
hull.append(line(b[0], 0))
for i in range(1, n):
    arg = a[i]
    while len(hull) > 1 and hull[0].get(arg) >= hull[1].get(arg):
        hull.popleft()
    ans = hull[0].get(arg)
    nl = line(b[i], ans)
    while len(hull) > 1 and check(hull[-2], hull[-1], nl):
        hull.pop()
    hull.append(nl)

print(ans)