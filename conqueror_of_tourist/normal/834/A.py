l = input().split()
n=int(input())

l2 = []

for c in l:
    if ord(c) == 118:
        l2.append(0)
    elif ord(c) == 60:
        l2.append(1)
    elif ord(c) == 94:
        l2.append(2)
    elif ord(c) == 62:
        l2.append(3)

diff = l2[1] - l2[0]

cw = (diff-n)%4 == 0
ccw = (diff+n)%4 == 0
if cw and ccw:
    print('undefined')
elif cw:
    print('cw')
else:
    print('ccw')