t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if n % 2 ==  k % 2 and n >= k:
        print('YES')
        out = [1] * k
        out[0] += (n - k)
        print(*out)
    elif n % 2 == 0 and n >= 2 * k:
        print('YES')
        out = [2] * k
        out[0] += (n - 2*k)
        print(*out)
    else:
        print('NO')