s = input().strip()
l = []
for c in s:
    l.append(ord(c)-65)
for i in range(len(l)-2):
    if l[i+2] != (l[i] + l[i+1]) % 26:
        print('NO')
        break
else:
    print('YES')