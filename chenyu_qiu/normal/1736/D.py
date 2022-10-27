for t in range(int(input())):
	n = int(input())
	a_str = input()
	a = [int(i) for i in a_str]
	d = []
	if(sum(a) % 2 == 1):
		print(-1)
		continue
	for i in range(n):
		if a[2*i] != a[2*i + 1]:
			if len(d) % 2 == a[2*i]:
				d.append(2*i)
			else:
				d.append(2*i + 1)
	print(len(d), end = ' ')
	for i in range(len(d)):
		print(d[i] + 1, end = ' ')
	print()
	for i in range(n):
		print(2*i+1, end = ' ')
	print()