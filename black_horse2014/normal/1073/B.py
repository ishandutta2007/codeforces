n = int(input())
a = input().split()
b = input().split()
mx = -1
pos={}
for i, ai in enumerate(a):
	pos[a[i]] = i;
for x in b:
	if (mx != -1):
		print(' ', end='')
	if (pos[x] > mx):
		print(pos[x] - mx, end='')
		mx = pos[x];
	else:
		print(0, end='')