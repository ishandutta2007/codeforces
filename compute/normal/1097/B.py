n=int(input())
all=[]
for i in range(0,n):
    tmp=int(input())
    all.append(tmp)
def dfs(cur,ang):
    if cur==n:
        return ang%360==0
    return dfs(cur+1,ang+all[cur])or dfs(cur+1,ang-all[cur])
if dfs(0,0):
    print('YES')
else :
    print('NO')