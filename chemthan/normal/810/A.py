import math

line = lambda: map(int, input().split())

def solve():
    n, k = line()
    s = sum(line())
    print(max(0, (k + k - 1) * n - s - s))
    
def main():
    solve()
    exit(0)

if __name__ == "__main__":
        main()