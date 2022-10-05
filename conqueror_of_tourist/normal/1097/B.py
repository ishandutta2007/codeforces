n = int(input())
l = []
for i in range(n):
    l.append(int(input()))

s = sum(l)

out = False

for test in range(pow(2, n)):
    snew = sum([l[i] for i in range(n) if (test & pow(2,i) != 0)])
    if (s - 2 * snew) % 360 == 0:
        out = True
        break

if out:
    print('YES')
else:
    print('NO')