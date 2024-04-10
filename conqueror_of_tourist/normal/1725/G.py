lo = 0
hi = 10 ** 10

N = int(input())
while hi - lo > 1:
    mid = (lo + hi) // 2

    m = mid
    ct = 0

    ct += (m + 1) // 2
    m //= 4
    ct += m

    if mid >= 1:
        ct -= 1
    if mid >= 4:
        ct -= 1

    if ct >= N:
        hi = mid
    else:
        lo = mid
print(hi)