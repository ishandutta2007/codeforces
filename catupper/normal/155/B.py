a=input()
zero=[]
res=0
chance=1
for x in range(a):
	k,j=map(int,raw_input().split())
        if(j==0):zero+=[k]
	else:
		chance+=j-1
		res+=k

zero.sort()

res+=sum(zero[-chance:])


print res