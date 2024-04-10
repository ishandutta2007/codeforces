n=int(input())
a=list(input() for i in range(n))
for s in a:
	if len(s)<=10:
		print(s)
	else:
		print(s[0]+str(len(s)-2)+s[len(s)-1])