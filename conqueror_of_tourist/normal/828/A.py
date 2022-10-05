n, a, b = list(map(int,input().split()))
l = input().split()
o = 0
c = 0
for i in l:
    if i == '2':
        if b > 0:
            b -= 1
        else:
            o += 2
    if i == '1':
        if a > 0:
            a -= 1
        elif b > 0:
            b -= 1
            c += 1
        elif c > 0:
            c -= 1
        else:
            o += 1
print(o)