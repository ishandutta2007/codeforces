n = int(input())
mx = -1
ans = -1
cnt = [0] * (10**6 + 1)
for id in map(int, input().split()):
    cnt[id] += 1
    if cnt[id] > mx:
        mx = cnt[id]
        ans = id
print(ans)