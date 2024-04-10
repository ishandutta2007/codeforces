z=input
for _ in [0]*int(z()):
 z();c=m=d=n=0
 for v in map(int,input().split()):c+=v;m=max(m,c)
 z()
 for v in map(int,input().split()):d+=v;n=max(n,d)
 print(m+n)