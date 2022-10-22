a=input()
b=map(int,raw_input().split())

res=sum(b)
for x in range(1,a/3+1):
    if(a%x==0):
        for k in range(x):
            res=max(res,sum(b[k::x]))

print res