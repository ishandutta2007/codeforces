n,a,d = map(int,input().split())
it = 614945049
N = 3*(10**9)//2
u = a*it%(10**9)
v = d*it%(10**9)
print(u*N+1,v*N)