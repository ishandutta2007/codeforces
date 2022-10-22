a=input()
nums=map(int,raw_input().split())
nums.sort()
if(nums[-1]==1):nums[-1]=2
else:nums[-1]=1
nums.sort()
for k in nums:
	print k,
print