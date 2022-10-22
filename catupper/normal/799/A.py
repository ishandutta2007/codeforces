n,t,k,d = map(int, raw_input().split())
a = (n / k + (n%k>0)) * t    
b = (a-1) / t * k + (a-1-d)/t*k
if a < d:
    b = (a-1) / t * k
if b >=  n:print "YES"
else:print "NO"