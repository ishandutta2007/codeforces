import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    l = list(map(int, input().split()))

    ll = [- l[i] + (n - 1 - i) for i in range(n)]

    ll.sort()

    base = sum(l)

    poss = [base]

    for i in range(k):
        base += ll[i] - i

        poss.append(base)

    print(min(poss))