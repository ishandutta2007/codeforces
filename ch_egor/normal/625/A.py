n=int(input())
a=int(input())
b=int(input())
c=int(input())
z=0
if b-c<a and n>c:
    z=(n-c)//(b-c)
    n-=z*(b-c)
z+=n//a
print(z)