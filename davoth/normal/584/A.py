n,t=map(int,input().split())
if n==1 and t==10:
    print(-1)
else:
    for i in range(10**(n-1), 10**(n-1)+t+1):
        if i%t==0:
            print(i)
            break