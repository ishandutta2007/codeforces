t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    big = max(l)
    tot = sum(l)
    big2 = (tot - 1)//(n-1) + 1
    print((n - 1) * max(big, big2) - tot)