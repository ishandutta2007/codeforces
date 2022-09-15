import math

def solve():
    n = int(input())
    ans = ""
    for i in range(0, n):
        if i % 4 <= 1:
            ans += "a"
        else:
            ans += "b"
    print(ans)
        
def main():
    solve()
    exit(0)

if __name__ == "__main__":
        main()