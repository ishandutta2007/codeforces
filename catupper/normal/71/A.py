a=int(raw_input())
for i in range(a):
	t=raw_input()
	if len(t)>10:
		print t[0]+str(len(t)-2)+t[len(t)-1]
	else:
		print t