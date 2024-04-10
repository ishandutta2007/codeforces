inp = input().split()
n = int(inp[0])
t = int(inp[1])
c = int(inp[2])
pris = list(map(int, input().split()))
last = -1
ans = 0
for i in range(n+1):
    if i == n or pris[i] > t:
        ans += max(0, i - last - c)
        last = i
print(ans)