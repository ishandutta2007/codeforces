n = int(input())

for _ in range(n):
    a, b, c = map(int, input().split())

    print(min((a+b+c)//2, a+b, a+c, b+c))