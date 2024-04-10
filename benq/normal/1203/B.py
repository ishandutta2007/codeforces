def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def solve():
    n = nextInt()
    a = nextInts()
    a.sort()
    area = -1
    for i in range(n):
        if a[2*i] != a[2*i+1]:
            return False
        if a[4*n-1-2*i] != a[4*n-2-2*i]:
            return False
        tmp = a[2*i]*a[4*n-1-2*i]
        if area == -1:
            area = tmp
        elif area != tmp:
            return False
    return True

q = nextInt()
for i in range(q):
    print("YES" if solve() else "NO")