import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    ct = [0] * n

    for v in a:
        if v < n:
            ct[v] += 1
        else:
            break

    kr = k
    for i in range(n):
        if ct[i]:
            pass
        else:
            if kr:
                kr -= 1
            else:
                break
    else:
        out.append(0)
        continue

    bmex = i

    bad = []

    for i in range(n):
        if a[i] >= bmex:
            if i == 0 or a[i] != a[i-1]:
                bad.append(0)
            bad[-1] += 1

    bad.sort(reverse = True)
    
    while bad:
        if bad[-1] <= k:
            k -= bad[-1]
            bad.pop()
        else:
            break
    
    
    out.append(len(bad))

print('\n'.join(map(str, out)))