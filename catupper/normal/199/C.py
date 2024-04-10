k,b,n,t=map(int,raw_input().split())
x=1
n+=1
while(x<t):
    x=x*k+b
    n-=1
n-=(x==t)
print max(n,0)