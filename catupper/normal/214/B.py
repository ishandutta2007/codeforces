a=input()
m=map(int,raw_input().split())
if 0 not in m:
	print -1
	exit()

t=sum(m)%3

def sd(x):
	global m
	if x in m:
		m.pop(m.index(x))
		return True
	return False

if t==1:
	tt=0	
	if sd(1):
		tt=1
	elif sd(4):
		tt=1
	elif sd(7):
		tt=1
	if tt==0 and sd(2):
		if sd(2):
			tt=1
		elif sd(5):
			tt=1
		elif sd(8):
			tt=1
		if(tt==0):m+=[2]
	if tt==0 and sd(5):
		if sd(2):
			tt=1
		elif sd(5):
			tt=1
		elif sd(8):
			tt=1
		if(tt==0):m+=[5]
	if tt==0 and sd(8):
		if sd(2):
			tt=1
		elif sd(5):
			tt=1
		elif sd(8):
			tt=1
		if(tt==0):m+=[8]

if t==2:
	tt=0
	if sd(2):
		tt=1
	elif sd(5):
		tt=1
	elif sd(8):
		tt=1
	if tt==0 and sd(1):
		if sd(1):
			tt=1
		elif sd(4):
			tt=1
		elif sd(7):
			tt=1
		if(tt==0):m+=[1]
	if tt==0 and sd(4):
		if sd(1):
			tt=1
		elif sd(4):
			tt=1
		elif sd(7):
			tt=1
		if(tt==0):m+=[4]
	if tt==0 and sd(7):
		if sd(1):
			tt=1
		elif sd(4):
			tt=1
		elif sd(7):
			tt=1
		if(tt==0):m+=[7]

if sum(m)%3!=0:
	print -1
	exit()

m.sort()
m=m[::-1]

if sum(m)==0:
	print 0
	exit()


print ''.join(map(str,m))
##