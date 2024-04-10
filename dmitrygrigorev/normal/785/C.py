n, m = list(map(int, input().split()))
if m >= n:
    print(n)
else:
    start = n - m + 1
    r = 10 ** 11
    l = -1
    while (r - l > 1):
        mid = (l + r) // 2
        summ = mid * (mid + 1) // 2
        if summ >= n - m:
            r = mid
        else: 
            l = mid
    print(r + m)