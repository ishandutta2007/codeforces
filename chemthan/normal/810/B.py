import math

line = lambda: map(int, input().split())

def solve():
    n, f = line()
    ans = 0
    ar = []
    for i in range(n):
        k, l = line()
        ans += min(k, l)
        ar.append(min(k + k, l) - min(k, l))
    ar.sort(reverse = True)
    for i in range(f):
        ans += ar[i]
    print(ans)
    
def main():
    solve()
    exit(0)

if __name__ == "__main__":
    main()