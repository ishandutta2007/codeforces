n=int(input())
a=list(map(int,input().split()))
b=[0]*100
c=[0]*n
p=0
for _ in range(n):
    i=0;j=a[_]
    while(j%2==0):i+=1;j//=2
    b[i]+=1;c[_]=i
for _ in range(100):
    if b[_]>b[p]:p=_
print(n-b[p])
print(*[a[_] for _ in range(n) if c[_]!=p])