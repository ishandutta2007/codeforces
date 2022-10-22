import random
import math

ans = []
n = int(input())
s = []


def query(x: int) -> int:
    print("sqrt", x, flush=True)
    return int(input())


def work(x: int, pos: int):
    for i in ans:
        while x % i == 0:
            x /= i
    if x == 1:
        return
    if pos == len(s):
        ans.append(x)
        return
    work(math.gcd(x, s[pos][0]), pos + 1)
    work(math.gcd(x, s[pos][1]), pos + 1)


for i in range(0, 50):
    a = random.randrange(0, n)
    if math.gcd(n, a) != 1:
        s.append([math.gcd(n, a), n // math.gcd(n, a)])
        continue
    b = query(a * a % n)
    if a == b:
        continue
    if a < b:
        a, b = b, a
    s.append([(a + b) % n, a - b])

work(n, 0)

print("!", len(ans), end=' ')
for i in ans:
    print(i, end=' ')
print()