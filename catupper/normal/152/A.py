a,b=map(int,raw_input().split())
t=[[] for x in range(b)]
for x in range(a):
	k=list(raw_input())
	for g in range(b):
		t[g]+=[k[g]]

n=[]
for x in range(b):
	m=max(t[x])
	for k in range(a):
		if(t[x][k]==m):n+=[k]

		
print len(set(n))