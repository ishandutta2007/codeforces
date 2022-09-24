n,m=map(int,input().split())
x = [1]
ans = 0
for i in range(1, n + 1):
    x.append(i * x[-1] %m)
for i in range(1,n+1):
    ans = ((n-i+1)*x[i]*x[n-i+1]%m + ans)%m
print(ans)