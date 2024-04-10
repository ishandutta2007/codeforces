from collections import Counter, deque, defaultdict
import math, sys
import sys, io, os
from itertools import permutations, accumulate
from heapq import *
from bisect import bisect_left, bisect_right
from functools import cmp_to_key
# https://github.com/cheran-senthil/PyRival/tree/master/pyrival
# https://docs.python.org/3/library/bisect.html
lcm = lambda x, y: (x * y) // math.gcd(x,y)
# cyclicly rotate all elements k to the left
rotate = lambda seq, k: seq[k:] + seq[:k]
input = sys.stdin.readline
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
'''
Check for typos before submit
Observations/Notes: 

'''
for _ in range(int(input())):
    buff = input()
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    # store first and last occurence
    first = {}
    for ind, num in enumerate(arr):
        if str(num) not in first:
            first[str(num)] = ind
    last = {}
    for i in range(n -1, -1, -1):
        if str(arr[i]) not in last:
            last[str(arr[i])] = i
        
    for i in range(k):
        a, b = input().split()
        if a not in last or b not in last:
            sys.stdout.write("NO\n")
        elif first[a] > last[b]:
            sys.stdout.write("NO\n")
        else:
            sys.stdout.write("YES\n")