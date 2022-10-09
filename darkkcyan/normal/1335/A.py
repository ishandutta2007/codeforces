for _ in range(int(input())):
    n = int(input())
    way = n // 2
    if n % 2 == 0:
        way -= 1
    print(way)