input()
lists=map(int,raw_input().split())
for x in lists:
	if x%4==1:
		print 2*x+1
	if x%4==0:
		print 4*x+1
	if x%4==3:
		print x+1
	if x%4==2:
		print 4*x+1