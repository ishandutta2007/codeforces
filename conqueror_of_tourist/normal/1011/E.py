def gcd(a,b):
    if b == 0:
        return a
    if b > a:
        return gcd(b,a)
    return gcd(b,a%b)

n,k = list(map(int,input().split()))
l = list(map(int,input().split()))

out = k
for i in l:
    out = gcd(i,out)

print(k//out)
print(' '.join(list(map(str,range(0,k,out)))))