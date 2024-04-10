l, r = list(map(int,input().split()))

def allDif(inp):
    L = [False] * 10

    while inp:
        val = inp % 10
        if L[val]:
            return False
        L[val] = True
        inp //= 10

    return True

while l < r:
    if allDif(l):
        break
    l += 1

if allDif(l):
    print(l)
else:
    print(-1)