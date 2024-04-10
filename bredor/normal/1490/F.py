from collections import*
I=input
for _ in' '*int(I()):
    s=n=int(I());c=0
    for x,y in sorted(Counter(Counter(map(int,I().split())).values()).items())[::-1]:
        c+=y
        s=min(s,n-c*x)
    print(s)
##