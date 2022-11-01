def max(a,b):
    if (a>b):
        return a
    return b

n=input()
p=list(map(int,raw_input().split()))
ans=0
f=[0 for i in xrange(n+1)]
for i in xrange(n):
    f[p[i]]=f[p[i]-1]+1
    ans=max(ans,f[p[i]])
print n-ans