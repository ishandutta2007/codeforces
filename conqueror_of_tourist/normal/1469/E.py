import sys
input = sys.stdin.readline

t = int(input())
outL = []
for _ in range(t):
    n, k = map(int, input().split())
    s = input().strip()
    bad = set()
    k2 = min(k, 20)
    last = -1
    curr = 0
    mask = (1 << k2) - 1
    for i in range(n):
        curr *= 2
        if s[i] == '0':
            curr += 1
        if curr > mask:
            curr &= mask
            last = i
        if i >= k-1 and (i - last) >= (k-k2):
            bad.add(curr)
    
    for i in range(1 << k2):
        if i not in bad:
            outL.append('YES')
            out = bin(i)[2:]
            outL.append('0'*(k-len(out))+out)
            break
    else:
        outL.append('NO')
print('\n'.join(outL))