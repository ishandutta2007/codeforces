def gt(a):
	hr = a[:2]
	mi = a[3:5]
	t = a[6]
	p = (int(hr)%12)*60+int(mi)
	if t == "p":
		return p + 100000
	return p

n = int(input())
s = [input()[1:8] for i in range(n)]
cnt = 1
sc = 1
for i in range(1, n):
	if s[i] == s[i-1]:
		sc += 1
		if sc == 11:
			sc = 1
			cnt += 1
	else:
		sc = 1
	cnt += (gt(s[i-1]) > gt(s[i]))
print(cnt)