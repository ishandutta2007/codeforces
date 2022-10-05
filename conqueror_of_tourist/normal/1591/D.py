import sys
input = sys.stdin.readline

def merge(A, l, r):
    n = r - l
    if n == 1:
        return 0

    out = 0
    m = (l + r)//2

    out += merge(a, l, m)
    out += merge(a, m, r)

    new = []
    left = A[l:m]
    right = A[m:r]

    while left and right:
        if right[-1] > left[-1]:
            new.append(right.pop())
        elif left[-1] > right[-1]:
            new.append(left.pop())
            out += len(right) % 2
        else:
            new.append(left.pop())
            out = 10 ** 14
            return out

    new = left + right + new[::-1]

    #print(A, l, r, new)

    for i in range(l, r):
        A[i] = new[i - l]
    return out
    

oo = []
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    #a = list(range(n))

    ct = merge(a, 0, n)

    #assert a == sorted(a)

    if ct > 10 ** 13 or ct % 2 == 0:
        oo.append('YES')
    else:
        oo.append('NO')
print('\n'.join(oo))