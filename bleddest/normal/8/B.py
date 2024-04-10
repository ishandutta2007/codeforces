s = input()
a = [[0, 0]]
for x in s:
    b = [a[-1][0], a[-1][1]]
    if x == 'D':
        b[0] += 1
    if x == 'U':
        b[0] -= 1
    if x == 'L':
        b[1] += 1
    if x == 'R':
        b[1] -= 1
    a.append(b)
    
n = len(a)
good = True
for i in range(n):
    for j in range(i + 2, n):
        if abs(a[j][0] - a[i][0]) + abs(a[j][1] - a[i][1]) <= 1:
            good = False

#print(a)
if good:
    print('OK')
else:
    print('BUG')