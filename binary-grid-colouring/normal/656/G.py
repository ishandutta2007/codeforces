n,m,k=map(int,input().split())
c=[0]*m
for i in range(n):
	a=input()
	for j in range(m):
		c[j]+=a[j]=='Y'
print(sum(c[i]>=k for i in range(m)))#kitten