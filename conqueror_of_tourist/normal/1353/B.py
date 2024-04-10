import sys
input = sys.stdin.readline
rInt = lambda: int(input())
mInt = lambda: map(int, input().split())
rLis = lambda: list(map(int, input().split()))

t = int(input())
for _ in range(t):
    n, k = mInt()
    a = rLis()
    b = rLis()
    a.sort()
    b.sort(reverse = True)
    for i in range(k):
        if a[i] < b[i]:
            a[i] = b[i]
    print(sum(a))