a=input()
b=map(int,raw_input().split())
INF=100000
ans=min(b[0],b[-1])

for x in range(1,a-1):
    ans=min(ans,max(b[x],b[x+1]))
print ans