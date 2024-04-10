from math import *

MOD = int(1e9)+7

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def YN(x):
    return "YES" if x else "NO"

def solve():
    N = nextInt()
    S = input()
    L = [0]*10
    for t in S:
        if t == 'L':
            cur = 0
            while L[cur] == 1:
                cur += 1
            L[cur] = 1
        elif t == 'R':
            cur = 9
            while L[cur] == 1:
                cur -= 1
            L[cur] = 1
        else:
            L[int(t)-int('0')] = 0
    return ''.join(str(x) for x in L)

print(solve())

# q = nextInt()
# for i in range(q):
#     print(YN(solve()))