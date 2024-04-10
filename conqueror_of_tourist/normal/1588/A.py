t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    b = sorted(map(int, input().split()))

    c = [b[i] - a[i] for i in range(n)]

    if min(c) >= 0 and max(c) <= 1:
        print('YES')
    else:
        print('NO')