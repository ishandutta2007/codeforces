a,b=map(int,raw_input().split())
posa,posb=map(int,raw_input().split())
k=input()
res=0
for x in range(k):
	da,db=map(int,raw_input().split())
	targa=1
	targb=1
	if(da>0):targa=a
	if(db>0):targb=b
	if(da==0):           
		move=((targb-posb)/db)
		posb+=db*move
	elif(db==0):
		move=((targa-posa)/da)
		posa+=da*move
	else:
		move=min(((targb-posb)/db),((targa-posa)/da))
		posb+=db*move
		posa+=da*move
	res+=move

print res