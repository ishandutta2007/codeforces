for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.append(0)
    arr.sort()
    print("YES" if arr[-1] - arr[-2] < 2 else "NO")