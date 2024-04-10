a,b=map(int,raw_input().split())
t=[[] for x in range(b)]
for x in range(a):
	k=list(raw_input())
	for n in range(b):
		t[n]+=[k[n]]


t=map(lambda j:len(set(j)),t)
res=1
for n in t:
	res*=n
	res%=((10**9)+7)
print res