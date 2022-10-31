s = list(map(int, input().split()))
ind = 0
while(s[1] > 0):
	if(s[1] < ind+1):
		break
	s[1] -= ind+1
	ind = (ind+1)%s[0]
print(s[1])