import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n, m, p=map(int, input().split())
x=list(map(int, input().split())) 
y=list(map(int, input().split())) 
a, b=0, 0
while (x[a]%p==0):
    a+=1
while (y[b]%p==0):
    b+=1
print(a+b)