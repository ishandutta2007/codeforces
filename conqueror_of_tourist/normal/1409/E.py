t=int(input());f=input
for _ in range(t):
 n,k=map(int,f().split());x=sorted(map(int,f().split()));f();r=[0]*n;c=n-1
 for i in range(n-1,-1,-1):
  while x[c] > x[i] + k:
   c-=1
  r[i]=c
 m=[0]*n;c=0
 for i in range(n-1,-1,-1):
  m[i]=c
  c=max(r[i]-i+1,c)
 o=[r[i]-i+1+m[r[i]] for i in range(n)]
 print(max(o))