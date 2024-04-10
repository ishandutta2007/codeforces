n = int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
m=998244353
k=[a[i]*(n-i)*(i+1)for i in range(n)]
k.sort(reverse=True);b.sort()
print(sum(k[i]*b[i]%m for i in range(n))%m)