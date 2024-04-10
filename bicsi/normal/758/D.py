n = int(input())
k = int(input())


sk = str(k)

inf = 1
for i in range(800):
	inf *= 10
	
#print "shit"

dp = [0] * (len(sk) + 1)

for i in range(1, len(sk) + 1):
	#print("i: " + str(i))
	
	pw = 1
	no = 0
	
	dp[i] = inf
	for j in range(i - 1, -1, -1):
		#print("j: " + str(j))
		
		no += pw * (ord(sk[j]) - ord('0'))
		
		if(no >= n):
			break
		if(sk[j] != '0' or pw == 1):
			if(dp[i] > dp[j] * n + no):
				dp[i] = dp[j] * n + no
				
		pw *= 10

print dp[len(sk)]