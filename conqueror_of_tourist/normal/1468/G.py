import sys
input = sys.stdin.readline

n, H = map(int, input().split())
points = [tuple(map(int, input().split())) for _ in range(n)]
eye = (points[-1][0], points[-1][1] + H)
peak = points[-1]

out = 0

def dot(a,b):
    return a[0] * b[0] + a[1] * b[1]
    
def sub(a,b):
    return (a[0] - b[0], a[1] - b[1])
    
def norm(a):
    return (a[0] ** 2 + a[1] ** 2) ** (0.5)

for _ in range(n-2,-1,-1):
    p1 = points[_]
    p2 = points[_ + 1]
    
    vecP = sub(peak, eye)
    vecR = (vecP[1], -vecP[0])
    
    vecP1 = sub(p1, eye)
    vecP2 = sub(p2, eye)
    
    h1 = dot(vecP1, vecR)
    h2 = dot(vecP2, vecR)
    
    if h2 >= 0:
        if h1 >= 0:
            out += norm(sub(p1,p2))
            peak = p1
    else:
        if h1 >= 0:
            out += norm(sub(p1,p2)) * (h1/(h1-h2))
            peak = p1
    
    
print(out)