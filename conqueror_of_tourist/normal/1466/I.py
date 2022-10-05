import random
import sys
input = sys.stdin.readline

def calc(li):
    l = sorted(li)
    out = 0
    for v,_ in l:
        out *= 2
        if v > 1:
            out += v
    return out

n, b = map(int, input().split())

curr = [(1<<b, i + 1) for i in range(n)]
currv = calc(curr)

ext = 0

count = 0
def out(ind, val):
    global count, ext
    s = bin(val+ext)[2:]
    s = '0' * (b - len(s)) + s
    print(ind, s)
    sys.stdout.flush()
    count += 1

    t = (input()).strip()
    return t == 'yes'

while curr:
    curr.sort()
    while curr and curr[0][0] <= 1:
        curr.pop(0)

    if len(curr) == 0:
        break

    #if currv/calc(curr) == 1:
    #    print(curr)
    #print(currv/calc(curr), len(curr))
    currv = calc(curr)

    lo = 0
    hi = curr[-1][0] - 1
    while hi - lo > 1:
        t = (lo + hi)//2

        ifn = currv//2 + t * (1 << (len(curr) - 1))
        ify = currv - t * (1 << (len(curr) - 1)) if curr[0][0] >= t else currv - t * (1 << (len(curr) - 2))
        
        if (ifn) < (ify):
            lo = t
        else:
            hi = t

    q = out(curr[-1][1], lo)
    if q:
        ext += lo + 1
        curr = [(v - (lo + 1),_) for v,_ in curr]
    else:
        curr[-1] = (lo + 1, curr[-1][1])
    
s = bin(ext)[2:]
s = '0' * (b - len(s)) + s
print(0, s)
sys.stdout.flush()