n = int(input())

ans = []
for x in list(map(int, input().split()))[::-1]:
    if x not in ans:
        ans.append(x)

print(len(ans))
print(*ans[::-1])