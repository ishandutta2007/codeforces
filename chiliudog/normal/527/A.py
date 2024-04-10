
a,b=list(map(int,raw_input().split()))
ans=0
while (True):
    if(a>b):
        t=a
        a=b
        b=t
    if(b%a==0):
        break
    ans+=b/a
    b%=a
print ans+(b/a)