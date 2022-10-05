t=int(input())
for _ in[0]*t:
 n=int(input())
 c=[0]*99
 for v in map(int,input().split()):
     while v>n:v//=2
     c[v]+=1
 for i in range(n,0,-1):
     if c[i]:
         c[i//2]+=c[i]-1
     else:
         break
 else:
     print('YES')
     continue
 print('NO')