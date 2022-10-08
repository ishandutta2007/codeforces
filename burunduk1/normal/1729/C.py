for _ in range(int(input())):
	s = input()
	ans = []
	for i in range(1,len(s)-1):
		if (ord(s[0])-ord(s[i]))*(ord(s[-1])-ord(s[i])) <= 0:
			ans.append((s[i],i))
	ans.sort()
	if ord(s[0]) > ord(s[-1]): ans = ans[::-1]
	print(abs(ord(s[0])-ord(s[-1])), len(ans)+2)
	print(1, *[i+1 for c, i in ans], len(s))