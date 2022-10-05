t = int(input())
for _ in range(t):
    x, y, n = map(int, input().split())
    y %= x
    k = n
    k -= k % x
    k += y % x
    k += x
    while k > n:
        k -= x
    print(k)