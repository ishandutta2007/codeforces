import sys
input = sys.stdin.readline
import random

def q1(a, b):
    print(1,a,b)
    sys.stdout.flush()
    return int(input())

def order(l):
    if l == []:
        return l
    left = []
    right = []
    v = l.pop()
    for v2 in l:
        res = q1(v, v2)
        assert res != -1
        if res == 0:
            left.append(v2)
        else:
            right.append(v2)

    return order(left) + [v] + order(right)

t = int(input())
for _ in range(t):
    n = int(input())
    p = list(range(n))
    random.shuffle(p)
    path = order(p)

    left = [-1] * n
    curr = n
    for i in range(n-1, -1, -1):
        while curr > 0:
            if curr > i:
                curr = i
            else:
                print(2, path[i], curr, *path[:curr])
                sys.stdout.flush()
                res = int(input())
                assert res != -1
                if res == 1:
                    curr -= 1
                else:
                    break
        left[i] = curr
    tl = []
    last = -1
    for i in range(n):
        if left[i] == i:
            tl.append(i)
            last = i
        else:
            tl.append(tl[left[i]])
            assert tl[-1] == last
    out = [''] * n
    for i in range(n):
        curr = ['0']*n
        for j in range(tl[i],n):
            curr[path[j]] = '1'
        out[path[i]] = ''.join(curr)
    print(3)
    print('\n'.join(out))
    sys.stdout.flush()
    assert int(input()) == 1