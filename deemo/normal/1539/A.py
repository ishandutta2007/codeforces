te = int(input())
while te > 0:
    te -= 1
    n, x, t = map(int, input().split())
    temp = t//x
    temp = min(temp, n-1);
    ans = temp * n
    ans -= temp * (temp+1) // 2
    print(ans)