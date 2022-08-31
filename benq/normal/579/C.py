import sys
a,b = map(int,input().split())
if a<b:
	print(-1)
	sys.exit(0)
k = int(((a/b)+1)/2)
z = 2*k*b/(a+b)
print(a/(2*k-z))