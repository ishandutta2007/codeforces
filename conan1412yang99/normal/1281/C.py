t = int(input())
a = [0] * 1000006
for iii in range(t):
	x = int(input())
	s = input()
	l = 0
	ln = len(s)
	full = False
	for i in range(ln):
		a[i+1] = ord(s[i]) - ord('0')
	while(True):
		l += 1
		sl = a[l]
		newlen = l + (ln - l) * sl
		if not full:
			for i in range(ln+1, min(newlen, x)+1):
				a[i] = a[i-(ln-l)]
			if(newlen >= x):
				full = True
		ln = newlen;
		if(full):
			ln %= 1000000007
		if(l == x):
			break;
	print(ln % 1000000007)