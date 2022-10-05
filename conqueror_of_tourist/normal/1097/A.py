i = input()
i2 = input().split(' ')

out = False

for s in i2:
    if s[0] == i[0] or s[1] == i[1]:
        out = True
        break

if out:
    print('YES')
else:
    print('NO')