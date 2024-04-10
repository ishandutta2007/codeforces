w = list(map(int,input().split()))
g = list(map(int,input().split()))
b = list(map(int,input().split()))

def cover(w,b):
    return b[0] <= w[0] and w[2] <= b[2] and b[1] <= w[1] and w[3] <= b[3]

def hcover(w,b1,b2):
    h = b1[0] <= w[0] and w[2] <= b1[2] and b2[0] <= w[0] and w[2] <= b2[2]
    v1 = b1[1] <= w[1] and b2[1] <= b1[3] and  w[3] <= b2[3]
    v2 = b2[1] <= w[1] and b1[1] <= b2[3] and  w[3] <= b1[3]

    return h and (v1 or v2)

def vcover(w,b1,b2):
    h = b1[1] <= w[1] and w[3] <= b1[3] and b2[1] <= w[1] and w[3] <= b2[3]
    v1 = b1[0] <= w[0] and b2[0] <= b1[2] and  w[2] <= b2[2]
    v2 = b2[0] <= w[0] and b1[0] <= b2[2] and  w[2] <= b1[2]
    
    return h and (v1 or v2)

if cover(w,b) or cover(w,g) or hcover(w,b,g) or vcover(w,b,g):
    print('NO')
else:
    print('YES')