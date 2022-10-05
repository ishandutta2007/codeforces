import sys
input = sys.stdin.readline

t = int(input())
out = []

for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    seen = dict()

    res = 0

    for i in range(n):
        v = l[i] - i

        if v in seen:
            res += seen[v]
        else:
            seen[v] = 0

        seen[v] += 1

    out.append(res)

print('\n'.join(map(str, out)))