t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    
    r,w = 0, 0
    for _ in range(m):
        rr, ww = map(int, input().split())
        r = max(r, rr)
        w = max(w, ww)
        
    if r + w > n:
        print('IMPOSSIBLE')
    else:
        print('R' * r + 'W' * (n - r))