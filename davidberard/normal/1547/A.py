TT = int(input())
 
for tt in range(TT):
    input()
    xa, ya = (int(x) for x in input().split())
    xb, yb = (int(x) for x in input().split())
    xf, yf = (int(x) for x in input().split())
    ans = abs(xa-xb)+abs(ya-yb)
    if xa==xb and xa==xf and min(ya, yb) < yf and yf < max(ya, yb):
        ans += 2
    if ya==yb and ya==yf and min(xa, xb) < xf and xf < max(xa, xb):
        ans += 2
    print(ans)