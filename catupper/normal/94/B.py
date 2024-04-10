def st():
	a=[[1,2,3],[1,2,4],[1,2,5],[1,3,4],[1,3,5],[1,4,5],[2,3,4],[2,3,5],[2,4,5],[3,4,5]]
	c=[True for x in a]        #no
	jk=[[False for p in range(5)] for q in range(5)]
	x=input()
	for n in range(x):
		p,q=map(int,raw_input().split())
		jk[p-1][q-1]=True
		jk[q-1][p-1]=True
		for j,k in enumerate(a):
			if k.count(q) and k.count(p):
				c[j]=False
	for n in a:
		if jk[n[0]-1][n[1]-1] and jk[n[1]-1][n[2]-1] and jk[n[0]-1][n[2]-1]:
			return 'WIN'	
	if any(c):return 'WIN'
	else:return 'FAIL'
	
	
print st()