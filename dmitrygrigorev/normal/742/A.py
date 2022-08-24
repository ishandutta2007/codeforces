n = int(input())
line = [8, 4, 2, 6]
if n > 0:
    print(line[(n-1) % 4])
else:
    print(1)