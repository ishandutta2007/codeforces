import math

def solve():
    n = int(input())
    a = [0 for i in range(n)]
    b = [0 for i in range(n)]
    change = 0
    better = 0
    for i in range(n):
        a[i], b[i] = list(int(x) for x in input().split())
        if a[i] != b[i]:
            change = 1
        for j in range(i):
            if a[j] < a[i]:
                better = 1
    if change:
        print("rated")
    else:
        if better:
            print("unrated")
        else:
            print("maybe")
    
def main():
    solve()
    exit(0)

if __name__ == "__main__":
        main()