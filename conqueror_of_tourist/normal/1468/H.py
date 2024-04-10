import heapq

t = int(input())
for _ in range(t):
    n, k, m = map(int, input().split())
    l = [0] + list(map(int, input().split())) + [n+1]
    diffs = [l[i+1]-l[i]-1 for i in range(m+1)]
    if sum(diffs) % (k-1) > 0:
        print('NO')
        continue

    ls = 0
    ind = -1
    while ls < k//2:
        ind += 1
        ls += diffs[ind]

    rs = 0
    ind2 = m+1
    while rs < k//2:
        ind2 -= 1
        rs += diffs[ind2]

    if ind2 <= ind:
        print('NO')
    else:
        print('YES')