n, b, d = list(map(int, input().split()))
line = list(map(int, input().split()))
othodes = 0
result = 0
for i in range(n):
    if line[i] <= b:
        othodes += line[i]
    if othodes > d:
        result += 1
        othodes = 0
print(result)