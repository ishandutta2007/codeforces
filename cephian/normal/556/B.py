n = int(input())
nums = list(map(int, input().split()))

diff = (0 - nums[0]) % n
m = -1
ok = True
for i in range(1, n):
    if((nums[i] + m*diff)%n != i):
        ok = False
    m *=-1
if ok:
    print("Yes")
else:
    print("No")