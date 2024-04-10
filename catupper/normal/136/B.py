b,a=map(int,raw_input().split())
res=0
dig=1
while(a!=0 or b!=0):
	res+=dig*(((a%3)+3-b%3)%3)
	dig*=3
	a/=3
	b/=3
print res