n = int(input())
corr = 0
for i in range(1, n + 1):
    corr += (n // i)
    
total = 0

count = [0] * 9
for i in range(1, n + 1):
    count[i % 9] += 1
    
mult = [0]*9
for i in range(9):
    for j in range(9):
        mult[(i * j) % 9] += count[i] * count[j]

for i in range(9):
    total += mult[i] * count[i]


print(total - corr)