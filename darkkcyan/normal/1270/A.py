for i in range(int(input())):
    n, k1, k2 = map(int, input().split())
    u = max(map(int, input().split()))
    v = max(map(int, input().split()))
    if u < v:
        print('NO')
    else:
        print('YES')