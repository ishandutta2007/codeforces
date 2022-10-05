t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    work = False
    for i in range(n - 1):
        if abs(l[i] - l[i+1]) >= 2:
            print('YES')
            print(i + 1, i + 2)
            work = True
            break

    if not work:
        print('NO')