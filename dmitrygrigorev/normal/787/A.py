a, b = list(map(int, input().split()))
c, d = list(map(int, input().split()))
yes = True
for i in range(1, 100):
    if a % i == c % i and c % i == 0:
        if d % i != b % i:
            yes = False
if not yes:
    print(-1)
else:
    s = set()
    for i in range(1000):
        s.add(b)
        b += a
    for i in range(1000):
        if d in s:
            print(d)
            break
        d += c