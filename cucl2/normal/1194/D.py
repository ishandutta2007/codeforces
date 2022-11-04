Q=int(input())
for q in range(Q):
	n,m=map(int,input().split())
	if m%3==0 and n>=m:
		n%=m+1
	if n%3 or n==m:
		print("Alice")
	else:
		print("Bob")