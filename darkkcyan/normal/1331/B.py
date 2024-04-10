a = int(input())
for i in range(2, a):
    if a % i != 0:
        continue
    print(i, a // i, sep='')
    break