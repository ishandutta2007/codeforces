from sys import stdin
n = int(stdin.readline())
ans = 0
dp = 0
last = 0
for i in map(int, stdin.readline().split()):
    if i <= last:
        dp = 0
    dp += 1
    last = i
    ans = max(ans, dp)
print(ans)