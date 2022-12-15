arr = [1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000]
x = int(input())
for y in arr:
    if y > x:
        print(y)
        exit(0)