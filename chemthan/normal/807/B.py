import math

def check(s, p):
    k = s // 50 % 475
    for i in range(25):
        k = (k * 96 + 42) % 475
        if 26 + k == p:
            return True
    return False

def solve():
    p, x, y = list(int(i) for i in input().split())
    for i in range(0, 100000):
        if x - 50 * i >= y:
            if check(x - 50 * i, p):
                print(0)
                return
    for i in range(0, 100000):
        if x + 50 * i >= y:
           if check(x + 50 * i, p):
               print((i + 1) // 2)
               return
    
def main():
    solve()
    exit(0)

if __name__ == "__main__":
        main()