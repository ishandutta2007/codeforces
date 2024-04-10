import math

def solve():
    l, r = list(int(x) for x in input().split())
    ans = l
    mx = 1
    for i in range(2, 100):
        cnt = r // i - (l - 1) // i
        if mx < cnt:
            mx = cnt
            ans = i
    print(ans)
        
def main():
    solve()
    exit(0)

if __name__ == "__main__":
        main()