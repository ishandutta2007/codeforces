t = int(input())
for _ in range(t):
    a,b = map(int, input().split())
    print(max((2*a - 1, 2*b - 1, a + b)))