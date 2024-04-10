s = input()
x = 0
for i in s:
    if (i == '1'):
        x = x * 2 + 1
    else:
        x = x * 2
ans = 0
y = 1
while (y < x):
    ans += 1
    y *= 4
print(ans)