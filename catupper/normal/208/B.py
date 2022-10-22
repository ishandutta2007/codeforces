a=input()
card=raw_input().split()
table=[[[[-1 for x in range(52)] for w in range(53)] for y in range(53)] for z in range(53)]
#maisuu(0index) -1 -2 -3

def ok(t,u):
	return t[0]==u[0] or t[1]==u[1]

mark={}
mark["2"]=0
mark["3"]=1
mark["4"]=2
mark["5"]=3
mark["6"]=4
mark["7"]=5
mark["8"]=6
mark["9"]=7
mark["T"]=8
mark["J"]=9
mark["Q"]=10
mark["K"]=11
mark["A"]=12
num={}
num["S"]=0
num["D"]=1
num["H"]=2
num["C"]=3

def tonum(kard):
	return mark[kard[0]]+13*num[kard[1]]

def solve(kard):
	if len(kard)==1:
		return True
	if len(kard)==2:
		if ok(kard[0],kard[1]):
			return True
		return False
	if table[len(kard)-1][tonum(kard[-1])][tonum(kard[-2])][tonum(kard[-3])]!=-1:
		return 	table[len(kard)-1][tonum(kard[-1])][tonum(kard[-2])][tonum(kard[-3])]
	res=False
	kk=kard[::]
	if ok(kard[-1],kard[-2]):
		kk[-2]=kk[-1]
		kk.pop()
		res=res or solve(kk)
	kk=kard[::]
	if len(kard)>3 and ok(kard[-1],kard[-4]):
		kk[-4]=kk[-1]
		kk.pop()
		res=res or solve(kk)
	table[len(kard)-1][tonum(kard[-1])][tonum(kard[-2])][tonum(kard[-3])]=res
	return res

if solve(card):
	print "YES"
else:
	print "NO"