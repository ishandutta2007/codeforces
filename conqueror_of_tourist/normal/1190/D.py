import bisect

import sys
input = sys.stdin.readline

def ch(n):
    return (n*(n+1))//2

n = int(input())
d = dict()
for _ in range(n):
    x,y = map(int,input().split())
    if y in d.keys():
        d[y].append(x)
    else:
        d[y] = [x]

yVals = sorted(d.keys())

first = yVals.pop()
xVals = sorted(d[first])

size = len(xVals)
out = ch(size)
while yVals != []:
    nex = yVals.pop()
    newX = sorted(d[nex])
    remove = 0
    position = -1
    for val in newX:
        newPos = bisect.bisect_left(xVals,val,0 if position < 0 else position)
        if newPos < size and xVals[newPos] == val:
            remove += ch(newPos-position-1)
            position = newPos
        else:
            remove += ch(newPos-position-1)
            position = newPos
            size += 1
            xVals.insert(newPos,val)
    remove += ch(size - position - 1)
    out += (ch(size)- remove)

print(out)