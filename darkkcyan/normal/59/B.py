n = int(input())
b = [[], []]
for i in map(int, input().split()):
    b[i % 2].append(i)

if len(b[1]) == 0:
    print(0)
else:
    ans = sum(b[0]) + sum(b[1])
    if len(b[1]) % 2 == 0:
        ans -= min(*b[1])
    print(ans)