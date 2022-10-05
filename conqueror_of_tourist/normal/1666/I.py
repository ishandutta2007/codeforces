import sys

input = sys.stdin.readline

def d(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) 

o1 = (14, 1)
o2 = (13, 3)

def query(x, y):
    print('SCAN',x + 1,y + 1)
    sys.stdout.flush()

    return int(input())
    #return d(o1, (x, y)) + d(o2, (x, y)) 

def cout(x1, x2, y1, t2):
    print('DIG',x1 + 1,y1 + 1)
    sys.stdout.flush()
    if int(input()) == 1:
        print('DIG',x2 + 1,y2 + 1)
        sys.stdout.flush()
        assert int(input()) == 1
    else:
        print('DIG',x1 + 1,y2 + 1)
        print('DIG',x2 + 1,y1 + 1)
        sys.stdout.flush()
        assert int(input()) == 1
        assert int(input()) == 1


t = int(input())
for _ in range(t):
    o1 = (5 + _//2, 1 + _//3)
    o2 = (6, 3)
    
    n, m = map(int, input().split())
    #n, m = 16, 15

    tl = query(0, 0)
    #tr = query(n - 1, 0)
    bl = query(0, m - 1)

    sX = (tl + bl - 2 * (m - 1))//2
    sY = tl - sX
    #sY = tl + tr - 2 * (n - 1)

    ml = query(0, sY//2)
    diffY = ml - sX
    assert diffY % 2 == sY % 2
    y1 = (sY//2 + (diffY + 1)//2)
    y2 = (sY//2 - (diffY//2))

    tm = query(sX//2, 0)
    diffX = tm - sY
    assert diffX % 2 == sX % 2
    x1 = (sX//2 + (diffX + 1)//2)
    x2 = (sX//2 - (diffX//2))

    #print(o1, o2)
    cout(x1, x2, y1, y2)