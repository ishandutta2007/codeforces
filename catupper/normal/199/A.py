p=input()
fib=[0,1]
a,b=0,1
while(b<=10**9):
	fib+=[a+b]
	a,b=b,a+b

if p==0:
	print "0 0 0"

elif p==1:
	print "0 0 1" 
	exit()
elif p==2:
	print '0 1 1'
else:
	t=fib.index(p)
	print fib[t-1],fib[t-3],fib[t-4]