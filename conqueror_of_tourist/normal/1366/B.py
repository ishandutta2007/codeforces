t = int(input())
for _ in range(t):
    n, x, m = map(int, input().split())

    left = x
    right = x

    for i in range(m):
        l,r = map(int, input().split())

        if l < left <= r:
            left = l
        if r > right >= l:
            right = r

    print(right - left + 1)