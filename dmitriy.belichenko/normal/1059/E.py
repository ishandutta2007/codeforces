n , l , s = map(int , input().split())
i , ans = n , 0
w , par , vis = [0] , [0 , 0] , [0] * (n + 10)
for u in map(int , input().split()):
    if(u > s):
        print(-1) , exit(0)
    w.append(u)
if(n > 1):
    for u in map(int , input().split()):
        par.append(u)
while(i > 0):
    if vis[i] == 0:
        c , p , x = i ,  l , s
        ans = ans + 1
        while(x >= w[c] and p * c > 0):
            vis[c] = 1
            p = p - 1
            x = x - w[c]
            c = par[c]
    i = i - 1
print(ans)