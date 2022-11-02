n = int(input())
x = sorted(map(int , input().split()))
print(x[(n - 1) // 2])