from sys import stdin, exit
n = int(stdin.readline())

exp = 10
for _ in range(n):
	a = int(stdin.readline())
	p10 = 1
	e10 = 0
	while p10 <=a:
		p10 = p10*10
		e10 = e10+1
		
	b = 5**exp * a % 2**e10
	b = (2**e10 - b) % 2**e10
	if b%5 == 0:
		b = b + 2**e10
	a = a*10**exp + b*2**exp
	e10 = e10 + exp
	
	#print(a)

	ans = -1
	cur = 2**(e10+5)
	for dig in range(1, e10+1): # match a from right to left
		step = 4*5**(dig-2) # periodicity of lower digits
		if dig == 1:
			step = 1
		b = a % 10**dig # suffix we want to match
		for i in range(5):
			x = pow(2, cur, 10**dig)
			if b==x:
				break;
			cur = cur + step
		else:
			break
	else:
		ans = cur

	print("{}".format(ans))
	#print(pow(2, ans, 10**100))