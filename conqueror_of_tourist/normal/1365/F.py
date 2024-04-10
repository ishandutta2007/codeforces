t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    works = True
    if n % 2:
        if a[n//2] != b[n//2]:
            works = False

    pairsA = []
    for i in range(n//2):
        f = a[i]
        s = a[n - i - 1]
        if f > s:
            f, s = s, f
        pairsA.append((f,s))

    pairsB = []
    for i in range(n//2):
        f = b[i]
        s = b[n - i - 1]
        if f > s:
            f, s = s, f
        pairsB.append((f,s))

    pairsA.sort()
    pairsB.sort()

    if works and pairsA == pairsB:
        print('Yes')
    else:
        print('No')