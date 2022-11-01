
import random
import sys

root=0

def is_square(apositiveint):
	a=apositiveint
	if a==0: return 0
	if a==1: return 1
	if a==2: return 0
	if a==3: return 0
	x = apositiveint // 2
	seen = set([x])
	while x * x != apositiveint:
		x = (x + (apositiveint // x)) // 2
		if x in seen: return 0
		seen.add(x)
	return x
  

n = sys.stdin.readline()
n=int(n)
l=[]
for k in range(200):
	b=2**(k+1)-3
	c=-2*n
	a=1
	#print b
	#print c
	delta=b*b-4*a*c
	#print delta
	if delta>=0:
		r=is_square(delta)
		#print r
		if r*r==delta:
			x1=(-b+r)/2
			if (x1>0 and x1%2==1): l.append(x1*(2**k))
			x1=(-b-r)/2
			if (x1>0 and x1%2==1): l.append(x1*(2**k))
	
l=list(set(l))
l=sorted(l)
if len(l)==0:
	print -1
else:
	for i in l:
		print i