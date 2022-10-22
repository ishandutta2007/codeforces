from sys import exit
from operator import itemgetter

def read():
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
    return [(x1, y1), (x2, y2), (x3, y3), (x4, y4)]

a = read()
b = read()

def calc(ls):
    s = 0
    for i in range(len(ls)):
        a = ls[i]
        b = ls[(i+1)%len(ls)]
        s += a[0] * b[1] - a[1] * b[0]
    return abs(s) / 2

def contain(sq, po):
    area = calc(sq)
    s = 0
    for i in range(len(sq)):
        s += calc([sq[i], sq[(i+1)%len(sq)], po])

    return abs(s - area) < 1e-3

for x in b:
    if contain(a, x):
        print("Yes")
        exit(0)

for x in a:
    if contain(b, x):
        print("Yes")
        exit(0)

x = sum(map(itemgetter(0), a)) / 4
y = sum(map(itemgetter(1), a)) / 4
if contain(b, (x, y)):
    print("Yes")
    exit(0)

x = sum(map(itemgetter(0), b)) / 4
y = sum(map(itemgetter(1), b)) / 4
if contain(a, (x, y)):
    print("Yes")
    exit(0)

print("No")