from sys import stdin, exit
from math import *

def main():
    def len_intersect(a, b, c, d):
        if d <= a or c >= b:
            return 0
        u, v = (max(a, c), min(b, d))
        return max(0, v - u)

    for testcase in range(int(stdin.readline())):
        a, b, c, r = map(int, stdin.readline().split())
        if a > b:
            a, b = b, a
        print(b - a - len_intersect(a, b, c - r, c + r))

if __name__ == '__main__':
    main()