import sys,heapq
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n,l,r = map(int, input().split())
    c = list(map(int, input().split()))

    if l > r:
        l,r = r,l
        c.reverse()

    left = [0] * n
    right = [0] * n
    for i in range(n):
        if i < l:
            left[c[i]-1] += 1
        else:
            right[c[i]-1] += 1

    pairs = 0
    ep = 0
    for i in range(n):
        m = min(left[i], right[i])
        left[i] -= m
        right[i] -= m
        pairs += m
        ep += right[i] // 2

    want = n // 2
    rem = want - pairs
    cost = rem + max(0, (r - want) - ep)
    out.append(cost)
print('\n'.join(map(str,out)))