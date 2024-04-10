n = (int)(input())
a = input()
g = "abcdefghijklmnopqrstuvwxyz"
def f(a) :
	for i in range (26) :
		if g[i] == a :
			return i
if n == 1 :
	print("Yes")
else :
	chk = []
	for i in range (26) :
		chk.append(0)
	for i in range(n) :
		chk[f(a[i])] += 1
	flg = 1;
	for i in range (26) :
		if chk[i] != 1 and chk[i] != 0 :
			flg = 0;
	if flg :
		print ("No")
	else :
		print ("Yes")