a,bfuck,b=map(str,input().split(' '))
a=int(a)
if b=="week":
	if a==5 or a==6:
		print("53")
	else:
		print("52")
else:
	if a<=29:
		print("12")
	elif a==30:
		print("11")
	else:
		print("7")