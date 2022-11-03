n = int(raw_input())
a = map(int, raw_input().split(' '))

c25 = c50 = c100 = 0

good = True

for i in a:
    if i == 50:
        if c25 == 0:
            good = False
        else:
            c25 -= 1
        c50 += 1
    elif i == 100:
        if c50 > 0 and c25 > 0:
            c50 -= 1
            c25 -= 1
        elif c25 > 2:
            c25 -= 3
        else:
            good = False
        c100 += 1
    else:
        c25 += 1

if good:
    print 'YES'
else:
    print 'NO'