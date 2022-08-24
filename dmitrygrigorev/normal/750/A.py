n, k = list(map(int, input().split()))
time = 240
counter = 0
summ = 0
while counter < n:
    if k + 5 * (counter + 1) + summ <= 240:
        counter += 1
        summ += 5 * (counter)
    else:
        break
print(counter)