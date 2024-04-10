a = list(input())
reach = False
lastnum = -1
last = int(a[-1])
for x in range(len(a)):
    if int(a[x]) % 2 == 0 and int(a[x]) < last:
        reach = True
        b = a[:]
        b[-1] = a[x]
        b[x] = a[-1]
        print(''.join(b))
        break
    elif int(a[x]) % 2 == 0:
        lastnum = x
        
if not(reach):
    if lastnum == -1:
        print(-1)
    else:
        x = lastnum
        b = a[:]
        b[-1] = a[x]
        b[x] = a[-1]
        print(''.join(b))