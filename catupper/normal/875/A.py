n = int(input())

def calc(x):
    return x + sum(map(int, list(str(x))))

ans = []

for i in range(200):
    if n-i <= 0:break
    if calc(n-i) == n:
        ans.append(n-i)

ans.sort()
print(len(ans))
for x in ans:print(x)