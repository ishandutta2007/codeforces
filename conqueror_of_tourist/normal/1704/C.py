import sys
input = sys.stdin.readline

out = []
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    l = list(map(int, input().split()))
    l.sort()

    gaps = []
    for i in range(m):
        curr = l[i]
        if i < m - 1:
            nex = l[i + 1]
        else:
            nex = l[0] + n
        gaps.append(nex - curr - 1)

    r = m
    gaps.sort(reverse = True)
    #print(gaps)
    for i in range(m):
        if gaps[i] == 4 * i + 1:
            r += 4 * i
        else:
            r += min(gaps[i], 4 * i + 1)
    out.append(r)
    

print('\n'.join(map(str, out)))