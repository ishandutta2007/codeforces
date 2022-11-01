n = int(input())
c1=list(map(int,input().split()))[1:]
c2=list(map(int,input().split()))[1:]
res=0
while c1 and c2:
	if res>1000:
		print(-1)
		exit()
	res+=1
	x,y=c1.pop(0),c2.pop(0)
	if x>y:
		c1+=[y,x]
	else :
		c2+=[x,y]
if c1:
	print(res,1)
else:
	print(res,2);