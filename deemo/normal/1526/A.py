te = int(input())
for _ in range(te):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a)
    l, r = 0, len(a)-1
    for i in range(n):
        print(a[l], a[r], end=' ')
        l += 1
        r -= 1
    print()