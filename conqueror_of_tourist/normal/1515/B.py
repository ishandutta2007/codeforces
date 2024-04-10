import sys,math
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n = int(input())

    o1 = math.isqrt(n//2)
    o2 = math.isqrt(n//4)

    if 2 * o1 * o1 == n or 4 * o2 * o2 == n:
        out.append('YES')
    else:
        out.append('NO')
print('\n'.join(out))