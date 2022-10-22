a,b,c=map(int,raw_input().split())

def sum(x):
	return x*(x+1)/2

print (b+a-1)*(c+a-1)-2*sum(a-1)