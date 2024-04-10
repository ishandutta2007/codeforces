def gcd(a,b): 
	if(b==0): 
		return a 
	else: 
		return gcd (b,a%b) 
a, b = map (int, input().split (' '))
if (b - a) >= 1000000 :
	print (1)
else:
	_gcd = b
	for i in range (a, b):
		_gcd = gcd (i, _gcd)
	print (_gcd)