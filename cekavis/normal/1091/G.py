import math
import random

n=int(input())
z=[n]

for i in range(15):
	x=random.randint(1, n-1)
	print('sqrt', x*x%n)
	x+=int(input())
	tmp=[]
	for a in z:
		tmp.append(math.gcd(x, a))
		tmp.append(a//tmp[-1])
	z=tmp

z=list(set(z)-{1})
print('!', len(z), *z)