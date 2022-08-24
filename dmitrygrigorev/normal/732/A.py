k, r = list(map(int, input().split()))
for i in range(1, 3000):
    if (i * k) % 10 == r or (i * k) % 10 == 0:
        print(i)
        break