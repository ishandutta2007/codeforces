n = int(input())
line = []
if n % 2 == 0:
    print(n // 2)
    for i in range(n//2):
        line += [2]
else:
    print(n // 2)
    for i in range(n//2 - 1):
        line += [2]
    line += [3]
print(" ".join(map(str, line)))