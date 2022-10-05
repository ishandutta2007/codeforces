import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    out = 0
    for i in range(n - 1):
        if b[i] != b[i + 1]:
            out = 1

    sort = 1
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            sort = 0

    if out or sort:
        print('Yes')
    else:
        print('No')