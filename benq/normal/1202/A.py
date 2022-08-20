from math import *
import sys
# import random

MOD = int(1e9)+7

def nextInt():
    return int(input())

def nextInts():
    return list(map(int,input().split()))

def YN(x):
    return "YES" if x else "NO"

def solve():
    x = input()
    y = input()
    ind = 0
    ans = 0
    while y[len(y)-1-ind] == '0':
        ind += 1
    while x[len(x)-1-ind] == '0':
        ind += 1
        ans += 1
    return ans

t = nextInt()
for i in range(t):
    print(solve())