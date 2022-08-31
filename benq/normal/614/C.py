import math
n,x,y = map(int,input().split())
li=[]
dis=[]
for i in range(n):
	a,b = map(int,input().split())
	li.append([a,b])
	dis.append((x-a)**2+(y-b)**2)

for i in range(n-1):
	a,b = li[i]
	m,n = li[i+1]
	if ((m-a)*(m-x)+(n-b)*(n-y))*((m-a)*(a-x)+(n-b)*(b-y))<=0:
		len = ((n-b)*x-(m-a)*y+m*b-a*n)**2/((n-b)**2+(m-a)**2)
		dis.append(len)
		
a,b = li[-1]	
m,n = li[0]

if ((m-a)*(m-x)+(n-b)*(n-y))*((m-a)*(a-x)+(n-b)*(b-y))<=0:
	len = ((n-b)*x-(m-a)*y+m*b-a*n)**2/((n-b)**2+(m-a)**2)
	dis.append(len)

print(math.pi*(max(dis)-min(dis)))