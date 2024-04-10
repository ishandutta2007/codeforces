mod = int(input())
h1, a1 = map(int, input().split())
x1, y1 = map(int, input().split())
h2, a2 = map(int, input().split())
x2, y2 = map(int, input().split())

q1 = 0
while h1 != a1:
    h1 = (h1 * x1 + y1) % mod
    q1 += 1
    if q1 > 2 * mod:
        print(-1)
        exit()

q2 = 0
t2 = h2
while t2 != a2:
    t2 = (t2 * x2 + y2) % mod
    q2 += 1
    if q2 > 2 * mod:
        print(-1)
        exit()

if q1 == q2:
    print(q1)
    exit()


c1 = 1
h1 = (a1 * x1 + y1) % mod
while h1 != a1:
    h1 = (h1 * x1 + y1) % mod
    c1 += 1
    if c1 > 2 * mod:
        print(-1)
        exit()

c2 = 0
nx2 = 1
ny2 = 0

for i in range(c1):
    nx2 = (nx2 * x2) % mod
    ny2 = (ny2 * x2 + y2) % mod

for i in range(q1):
    h2 = (h2 * x2 + y2) % mod

while h2 != a2:
    h2 = (h2 * nx2 + ny2) % mod
    c2 += 1
    if c2 > 2 * mod:
        print(-1)
        exit()

print(q1 + c1 * c2)