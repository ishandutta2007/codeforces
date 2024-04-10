inp = input().split()
n = int(inp[0])
m = int(inp[1])
tv = list(map(int, input().split()))
tv.sort()
ans = 0
for i in range(min(m, len(tv))):
    if(tv[i] >= 0):
        break
    ans -= tv[i]
print(ans)