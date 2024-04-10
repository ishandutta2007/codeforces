def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def ok(p):
    n = len(p)
    for i in range(n):
        x = p[i]%n+1
        if p[(i+1)%n] != x:
            return False
    return True

def solve():
    n = nextInt()
    p = nextInts()
    if ok(p):
        return True
    p.reverse()
    return ok(p)

q = nextInt()
for i in range(q):
    print("YES" if solve() else "NO")