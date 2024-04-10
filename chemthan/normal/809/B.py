import sys
import math

line = lambda: map(int, input().split())

def ask(x, y):
    print(1, x, y)
    sys.stdout.flush()
    return input() == "TAK"

def divide(l, r):
    d = r - l + 1
    if d == 1:
        return l
    m = (l + r) // 2
    if ask(m, m + 1):
        return divide(l, m)
    else:
        return divide(m + 1, r)

def solve():
    n, k = line()
    x = divide(1, n)
    y = x
    z = x
    if x > 1:
        y = divide(1, x - 1)
    if x < n:
        z = divide(x + 1, n)
    if ask(y, z) == False:
        y, z = z, y
    if x == y:
        y, z = z, y
    print(2, x, y)
    sys.stdout.flush()
    
def main():
    solve()
    exit(0)

if __name__ == "__main__":
    main()