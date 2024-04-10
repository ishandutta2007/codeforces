def lis(nums, cmp=lambda x, y: x <= y):
    P = [0] * len(nums)
    M = [0] * (len(nums) + 1)
    L = 0

    for i in range(len(nums)):
        lo, hi = 1, L

        while lo <= hi:
            mid = (lo + hi) // 2
            if cmp(nums[M[mid]], nums[i]):
                lo = mid + 1
            else:
                hi = mid - 1

        newL = lo
        P[i] = M[newL - 1]
        M[newL] = i

        L = max(L, newL)

    S = [0] * L
    k = M[L]

    for i in range(L - 1, -1, -1):
        S[i], k = nums[k], P[k]

    return S

n, v = map(int, input().split())
t = list(map(int, input().split()))
a = list(map(int, input().split()))

pos = []
for i in range(n):
    x = v * t[i] - a[i]
    y = v * t[i] + a[i]

    if x >= 0 and y >= 0:
        pos.append((x, y))

pos.sort()
li = [y for (x, y) in pos]

print(len(lis(li)))