import math
import random

n=int(input())
ans=[n]

for i in range(20):
    x=random.randint(1,n-1)
    y=x*x%n
    print("sqrt",y)
    z=(x+int(input()))%n
    nw=[]
    for u in ans:
        v=math.gcd(z,u)
        if v!=1 and v!=u:
            nw.append(v)
            nw.append(u//v)
        else:
            nw.append(u)
    ans=nw

print("!",len(ans),*ans)