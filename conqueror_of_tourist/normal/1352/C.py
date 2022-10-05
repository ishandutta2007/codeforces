t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    k -= 1
    out = (k % (n - 1))
    k //= (n - 1)
    out += k * n
    out += 1
    print(out)