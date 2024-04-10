n=input()
ans=0
for i in xrange(1,n+1):
    ans-=i-1
    ans+=(n-i+1)*i
print ans