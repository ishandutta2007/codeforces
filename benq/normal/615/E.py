import math

def printa(x,y):
	print(2*x+y," ",2*y);

n=int(input())
a=math.floor((-3+math.sqrt(9+12*n))/6)

while (3*a*(a+1) > n): 
	a -= 1
	
while (3*(a+1)*(a+2) <= n):
	a += 1
	
b=n-3*a*(a+1)

if (b == 0 or b == 1):
	printa(a,b)
	quit()
b -= 1
if (b >= 0 and b <= a):
	printa(a-b,b+1)
	quit()
b -= a
if (b >= 0 and b <= (a+1)):
	printa(-b,a+1)
	quit()
b -= (a+1)
if (b >= 0 and b <= (a+1)):
	printa(-a-1,a+1-b)
	quit()
b -= (a+1)
if (b >= 0 and b <= (a+1)):
	printa(-a-1+b,-b)
	quit()
b -= (a+1)
if (b >= 0 and b <= (a+1)):
	printa(b,-a-1)
	quit()
b -= (a+1)
printa(a+1,-a-1+b)