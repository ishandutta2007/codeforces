import sys
input = sys.stdin.readline

out = []
t = int(input())

for _ in range(t):
    n, x = map(int, input().split())
    l = list( map(int, input().split()))

    r = -1
    i = 0
    while i < n:
        lo = l[i]
        hi = l[i]
        
        j = i
        
        while j < n and lo + 2 * x >= hi:
            j += 1
            if j == n:
                break
            lo = min(l[j], lo)
            hi = max(l[j], hi)
        
            

        r += 1
        i = j

    out.append(r)

print('\n'.join(map(str, out)))