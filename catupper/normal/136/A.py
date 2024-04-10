a=input()
fri=map(int,raw_input().split())
res=range(a)
for k in range(a):
	res[fri[k]-1]=k+1

for k in res:
	print k,
print ''