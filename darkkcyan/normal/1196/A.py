from sys import stdin
from itertools import permutations

q = int(stdin.readline())
for i in range(q):
    x, y, z = map(int, stdin.readline().split())
    print((x + y + z) // 2)