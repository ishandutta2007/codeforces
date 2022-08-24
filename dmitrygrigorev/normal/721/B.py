n, k = list(map(int, input().split()))
line = []
for i in range(200):
    line += [0]
for i in range(n):
    password = input()
    line[len(password)] += 1
password = input()
length = len(password)
min_time = 0
max_time = 0
ostatok = k
for i in range(len(line)):
    if i != length:
        for j in range(line[i]):
            min_time += 1
            max_time += 1
            ostatok -= 1
            if ostatok == 0:
                ostatok = k
                min_time += 5
                max_time += 5
    else:
        min_time += 1
        for j in range(line[i] - 1):
            max_time += 1
            ostatok -= 1
            if ostatok == 0:
                ostatok = k
                max_time += 5  
        max_time += 1
        break
print(min_time, max_time)