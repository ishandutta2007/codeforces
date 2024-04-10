import sys,bisect
r=lambda:map(int,sys.stdin.readline().split())
M=998244353
f=lambda b:pow(b,M-2,M)
n,m=r()
d=sorted(r())
p=[0]
for v in d:p+=[p[-1]+v]
for _ in range(m):a,b=r();i=bisect.bisect(d,b-1);v=n-i; print([(p[i]*a*f(v+v*v)-p[-1]*(a*f(v)-1))%M,0][a>v])