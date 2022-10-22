a=input()
b=map(int,raw_input().split())

b.sort()

res=0
pen=0
time=350
prob=0
while(prob<len(b) and time>b[prob]):
	time-=b[prob]
	prob+=1
	res+=1

time=-time
while(prob<len(b) and time+b[prob]<=360):
	time+=b[prob]
	pen+=abs(time)
	prob+=1
	res+=1
	
print res,pen