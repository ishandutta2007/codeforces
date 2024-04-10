n = int(input())

coor = 0

for _ in range(n):
	k = input().split()
	t = int(k[0])
	dir = k[1]
	if dir[0] == 'N':
		coor -= t
		if coor < 0:
			print("NO")
			exit()
	elif dir[0] == 'S':
		coor += t
		if coor > 20000:
			print("NO")
			exit()
	else:
		if coor == 0 or coor == 20000:
			print('NO')
			exit()
if coor != 0:
	print("NO")
else:
	print("YES")