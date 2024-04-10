import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k > 4:
        k -= 2 * ((k - 5)//2)

    l = list(map(int, input().split()))
    for i in range(k):
        d = max(l)
        for j in range(n):
            l[j] = d - l[j]
    print(' '.join(map(str,l)))