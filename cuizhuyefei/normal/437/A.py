a=[]
for i in range(4):
	a.append(input()[2:])
'''
for i in range(4):
	print(a[i],len(a[i]))
'''
g=[]
for i in range(4):
	flag=1
	flag1=1
	for j in range(4):
		flag=flag and (i==j or len(a[i])>=2*len(a[j]))
		flag1=flag1 and (i==j or len(a[i])*2<=len(a[j]))
	if (flag or flag1):
		g.append(i)
if len(g)==1:
	print(chr(g[0]+65))
	exit()
print('C')