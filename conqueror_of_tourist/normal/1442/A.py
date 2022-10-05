import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    curr = 0
    for i in range(n-1):
        diff = l[i+1] - l[i]
        l[i] -= curr
        if diff > 0:
            curr += diff
    l[n-1] -= curr

    if min(l) >= 0:
        print('YES')
    else:
        print('NO')