import sys
input = sys.stdin.readline

t = int(input())

def is_pal(l):
    return l == l[::-1]

out = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    l = 0
    r = n - 1

    while l < r:
        if a[l] == a[r]:
            l += 1
            r -= 1
        else:
            break

    if l >= r-1:
        out.append('YES')
    else:
        assert a[l] != a[r]

        reml = [v for v in a[l:r+1] if v != a[l]]
        remr = [v for v in a[l:r+1] if v != a[r]]

        if is_pal(reml) or is_pal(remr):
            out.append('YES')
        else:
            out.append('NO')
        
print('\n'.join(map(str,out)))