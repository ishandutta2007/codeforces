t = int(input())
for _ in range(t):
    x, y, k = map(int, input().split())

    out = k
    want = k * y + k - 1
    div = x - 1

    out += (want + div - 1)//div
    print(out)