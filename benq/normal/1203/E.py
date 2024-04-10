from math import *

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def solve():
    cnt = [0]*150001
    n = nextInt()
    a = nextInts()
    for i in a:
        cnt[i] += 1
    lst = 0
    ans = 0
    for i in range(1,150001):
        for j in range(cnt[i]):
            res = max(i-1,lst+1)
            if res > i+1:
                break
            lst = res
            ans += 1
    return ans

print(solve())

# q = nextInt()
# for i in range(q):
#     print("YES" if solve() else "NO")