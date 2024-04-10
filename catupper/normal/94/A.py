def st():
	a=raw_input()
	a=[a[r*10:r*10+10] for r in range(8)]
	b=[raw_input() for r in range(10)]
	s=map(lambda x:b.index(x),a)
	res="".join(map(str,s))
	print res
	
st()