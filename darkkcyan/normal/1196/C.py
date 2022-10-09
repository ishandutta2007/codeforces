from sys import stdin
from math import inf

q = int(stdin.readline())

class Rect:
    def __init__(self, x1 = -inf, y1 = -inf, x2 = inf, y2 = inf):
        if x1 > x2:
            x1, x2 = x2, x1
        if y1 > y2:
            y1, y2 = y2, y1

        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def __str__(self):
        return "(%f, %f, %f, %f)" % (self.x1, self.y1, self.x2, self.y2)

def intersect(r1, r2):
    if r1 is None or r2 is None:
        return None
    if r1.x2 < r2.x1 or r2.x2 < r1.x1:
        return None
    if r1.y2 < r2.y1 or r2.y2 < r1.y1:
        return None
    return Rect(max(r1.x1, r2.x1), max(r1.y1, r2.y1), min(r1.x2, r2.x2), min(r1.y2, r2.y2))

for i in range(q):
    n = int(stdin.readline())

    inter = Rect()
    for i in range(n):
        x, y, f1, f2, f3, f4 = map(int, stdin.readline().split())
        curRect = Rect()
        if f1 == 0:
            curRect.x1 = x
        if f2 == 0:
            curRect.y2 = y
        if f3 == 0:
            curRect.x2 = x
        if f4 == 0:
            curRect.y1 = y
        inter = intersect(inter, curRect)
    if inter is None:
        print("0")
    else:
        print("1 %d %d" % (int(max(inter.x1, -10**5)), int(max(inter.y1, -10**5))))