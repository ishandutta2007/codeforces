'''def permutations(L):
    if L == []:
        return [[]]
    else:
        return [[h]+t for i,h in enumerate(L)
                      for t   in permutations(L[:i]+L[i+1:])]

def changes(a,b):
	t=''
	for x in range(len(a)):
		t+=a[b[x]]	
        return t

a,b=map(int,raw_input().split())
table=[]
for x in range(a):
	table.append(raw_input())
n=10**10
for k in permutations(range(b)):
	it=map(lambda x:changes(x,k),table)
	n=min(n,int(max(it))-int(min(it)))
print n
             '''  
	     
a,b,c=map(int,raw_input().split())
print min(a-b,c+1)