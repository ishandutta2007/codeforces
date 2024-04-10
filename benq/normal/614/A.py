l,r,k = map(int,input().split())
print(*([k**i for i in range(64) if l<=k**i<=r] or [-1]))