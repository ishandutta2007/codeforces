n = int(input())
x = [0 for i in range(0, 1010)]
for i in map(int, input().split()):
    x[i] += 1
d = 0
for i in range(0, 1010):
    d = max(d, x[i])
print(n - d)