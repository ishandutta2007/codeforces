l, r = map(int, input().split())
ans = -1
for x in range(l, r+1):
    if len(set(str(x))) == len(str(x)):
        ans = x
        break
print(ans)