n=input()
x=map(int,raw_input().split())
mono=map(int,raw_input().split())
res=0
rl=[0,0,0,0,0]
for k in x:
	res+=k
	for z in [4,3,2,1,0]:
		p=res/mono[z]
		rl[z]+=p
		res-=p*mono[z]

print rl[0],rl[1],rl[2],rl[3],rl[4]
print res