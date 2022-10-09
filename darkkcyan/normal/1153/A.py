from sys import stdin
import math

n, t = map(int, stdin.readline().split())
a = [tuple(map(int, stdin.readline().split())) for i in range(n)]
def first_arrive_time(s, d, t):
    while s < t:
        s += d
    return s

print(min(enumerate(a, 1), key = lambda x: first_arrive_time(x[1][0], x[1][1], t))[0])