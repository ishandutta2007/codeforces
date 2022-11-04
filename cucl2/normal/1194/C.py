Q=int(input())
for q in range(Q):
	s=input()
	t=input()
	p=input()
	hvp=[0]*26
	for i in p:
		hvp[ord(i)-97]+=1
	r=0
	can=1
	for l in range(len(s)):
		while r<len(t) and t[r]!=s[l]:
			nn=ord(t[r])-97
			r+=1
			if hvp[nn]==0:
				can=0
				break
			hvp[nn]-=1
		if r==len(t):
			can=0
		r+=1
		if can==0:
			break
	while r<len(t):
		nn=ord(t[r])-97
		r+=1
		hvp[nn]-=1
		if hvp[nn]<0:
			can=0
			break
	print("YNEOS"[1-can::2])