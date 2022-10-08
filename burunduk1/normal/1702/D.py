def solve():
	t = input()
	p = int(input())
	n = len(t)
	w = lambda i : ord(t[i])-ord('a')+1
	inds = sorted(range(n), key = lambda i: w(i))
	s = sum(map(w, range(n)))
	res = [t[i] for i in range(n)]
	while s > p:
		i = inds[-1]; inds.pop()
		res[i] = ''
		s -= w(i)
	print(''.join(res))

tn = int(input())
for _ in range(tn):
	solve()