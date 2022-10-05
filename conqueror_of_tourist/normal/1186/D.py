import math

n = int(input())

nums = []
bools = []

s = 0
for i in range(n):
    inp = float(input())
    dow = math.floor(inp)
    nums.append(dow)
    bools.append(inp != dow)
    s += dow

i = 0
while s != 0:
    if bools[i]:
        nums[i] += 1
        s += 1
    i += 1

for x in nums:
    print(x)