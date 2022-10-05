le = int(input())
s = input()
l = [0,0,0]#B,G,R
for i in range(le):
    c = s[i]
    if c == 'B':
        l[0] += 1
    elif c == 'G':
        l[1] += 1
    else:
        l[2] += 1
if min(l) > 0:
    print('BGR')
elif l[0] == 0 and l[1] == 0:
    print('R')
elif l[2] == 0 and l[1] == 0:
    print('B')
elif l[0] == 0 and l[2] == 0:
    print('G')
elif l[0] == 0:
    if l[1] == 1 and l[2] == 1:
        print('B')
    elif l[1] == 1:
        print('BG')
    elif l[2] == 1:
        print('BR')
    else:
        print('BGR')
elif l[1] == 0:
    if l[0] == 1 and l[2] == 1:
        print('G')
    elif l[0] == 1:
        print('BG')
    elif l[2] == 1:
        print('GR')
    else:
        print('BGR')
else:
    if l[1] == 1 and l[0] == 1:
        print('R')
    elif l[0] == 1:
        print('BR')
    elif l[1] == 1:
        print('GR')
    else:
        print('BGR')