# exit()  sys -   Python.      SystemExit,     ,    finally  try        .
n, m = map(int, input().split())
flag = [list() for x in range(n)]
h1 = True
for i in range(n):
    li= input()
    flag[i] = li
c0 = flag[0][0]
line = flag[0]
for j in range(1,m):
    if line[j] != c0:
        h1 = False
if not h1:
	cc = m / 3
	if m % 3 != 0:
		print('NO')
		exit()
	ch = ''
	color_ver = []
	for i in range(n):
		line = flag[i]
		kol  = 0
		for j in range(m):
			if j % cc == 0:
				if j != 0:
					kol +=1
				new_color = line[j]
				if new_color in color_ver and i == 0:
					print('NO')
					exit()
				else:
					color_ver.append(new_color)
				if new_color == ch:
					print('NO')
					exit()
				else:
					ch = new_color
				if ch != color_ver[kol]:
					print('NO')
					exit()
			if line[j] != ch:
				print('NO')
				exit()
else:
	cc = n / 3
	if n % 3 != 0:
		print('NO')
		exit()
	co = ''
	ch = list()
	kol = 0
	for i in range(n):
		line = flag[i]
		if i % cc == 0:
			if i != 0:
				kol +=1
			new_color = line[0]
			if new_color in ch:
				print('NO')
				exit()
			else:
				ch.append(new_color)
			if new_color != co:
				co = new_color
			else:
				print('NO')
				exit()
		for j in range(m):
			if line[j] != co:
				print('NO')
				exit()
print('YES')