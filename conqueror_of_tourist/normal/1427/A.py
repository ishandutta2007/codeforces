t = int(input())
for _ in range(t):
    n = int(input())
    l = sorted(map(int, input().split()))

    if sum(l) == 0:
        print('NO')
    elif sum(l) > 0:
        print('YES')
        print(' '.join(map(str,l[::-1])))
    else:
        print('YES')
        print(' '.join(map(str,l)))