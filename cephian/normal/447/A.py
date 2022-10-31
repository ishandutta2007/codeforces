inp = input().split()
p = int(inp[0])
n = int(inp[1])

hash = [False] * p
ans = -1
for i in range(n):
    a = int(input()) % p
    if hash[a]:
        ans = i + 1
        break
    hash[a] = True
    
print(ans)