input();k=0
for i in (list(map(int,input().split()))[::-1]):
    k=min(0,k+i)
print(-k)