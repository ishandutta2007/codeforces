import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    ct = [0] * (n + 1)
    for v in a:
        ct[v] += 1

    poss = []

    need = (n + k + 1) // 2
    assert need >= k + (n - need)
    assert need - 1 < k + (n - need + 1)

    right = 0
    curr = 0
    for left in range(n + 1):
        while curr < need and right <= n:
            curr += ct[right]
            right += 1
        if curr >= need:
            poss.append((left, right - 1))
        curr -= ct[left]

    x, y = min(poss, key = lambda x: x[1] - x[0])

    out.append(f'{x} {y}')

    start = 0
    curr = 0
    for i in range(n):
        v = a[i]
        if x <= v <= y:
            curr += 1
        else:
            curr -= 1
            
        if curr > 0 and k > 1:
            out.append(f'{start + 1} {i + 1}')
            start = i + 1
            curr = 0
            k -= 1

    assert curr > 0
    assert k == 1
    out.append(f'{start + 1} {n}')
            

print('\n'.join(out))