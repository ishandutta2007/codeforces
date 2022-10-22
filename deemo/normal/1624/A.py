te = int(input())
while te > 0:
    te -= 1
    n = int(input())
    a = list(map(int, input().split()))
    print(max(a) - min(a))