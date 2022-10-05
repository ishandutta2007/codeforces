N, S = map(int,input().split())

if 2 * N <= S:
    print('YES')
    out = [2] * N
    out[-1] += (S - 2 * N)
    print(*out, sep = ' ')
    print(1)
else:
    print('NO')