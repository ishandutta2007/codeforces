import math

sum=0
n=int(input())

for i in range(1,11):
	sum += i*max(min((9*math.pow(10,i-1)),(n-math.pow(10,i-1)+1)),0)
	
print(int(sum))