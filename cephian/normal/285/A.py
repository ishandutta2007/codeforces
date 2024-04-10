inp = input().split()
n = int(inp[0])
k = int(inp[1])
ans = []
for i in range(n, n-k, -1):
    ans.append(i)
for i in range(1, n-k+1):
    ans.append(i)
a = ''
for i in range(len(ans)):
    a += str(ans[i])
    if i != len(ans) - 1:
        a += ' '
print(a)