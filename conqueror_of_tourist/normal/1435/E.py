import sys
input = sys.stdin.readline

for _ in range(int(input())):
	a=input().strip().split(" ")
	d=int(a[3])
	c=int(a[2])
	b=int(a[1])
	a=int(a[0])
	if c*b<a:
		print("-1")
		continue
	kordi=a//(d*b)
	print(max(a+kordi*(a)-(d*b)*kordi*(kordi+1)//2,a))