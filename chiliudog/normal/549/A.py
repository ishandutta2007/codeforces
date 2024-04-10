n,m=map(int,input().split())
a=list(input() for i in range(n))
print(sum(sorted(a[i][j:j+2]+a[i+1][j:j+2])==sorted("face") for i in range(n-1) for j in range(m-1)))