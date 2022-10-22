a,b=map(int,raw_input().split())
t=map(int,raw_input().split())

for x in xrange(1,len(t)-1):
	if t[x]-1>t[x-1] and t[x]-1>t[x+1]:
		t[x]-=1
		b-=1
	if b==0:
		break

print " ".join(map(str,t))