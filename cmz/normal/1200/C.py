import math
(n,m,q)=map(int,input().split(' '))
l=n*m//math.gcd(n,m)
for i in range(q):
    (x1,y1,x2,y2)=map(int,input().split(' '))
    f1=y1*m
    f2=y2*m
    if x1==2:
        f1=y1*n
    if x2==2:
        f2=y2*n
    if (f1-1)//l!=(f2-1)//l:
        print('NO')
    else:
        print('YES')