n = int(input())
x = 0
y = 0
for i in range(n):
	a,b = map(int,input().split())
	x += (b-a)
	y = max(x,y)

print(y)