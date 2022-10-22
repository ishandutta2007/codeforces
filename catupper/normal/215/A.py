input()
a=map(int,raw_input().split())
input()
b=map(int,raw_input().split())
a.sort()
b.sort()
j=0
for x in a:
	for y in b:
		if y%x==0:
			j=max(j,y/x)
res=0
for x in a:
	if x*j in b:
		b.remove(x*j)
		res+=1

print res