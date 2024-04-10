import math

x=int(input())
x %= 360
x = 360-x
curnum=x
for i in range(4):
	if curnum <= 45:
		print(i)
		quit()
	if 360-curnum <= 45:
		print(i)
		quit()
	curnum = (curnum+90) % 360