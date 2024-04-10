n = int(input())
x = 0

for i in range(n):
	a,b,c=map(int,input().split())
	if a+b+c>1:
		x += 1

print(x)