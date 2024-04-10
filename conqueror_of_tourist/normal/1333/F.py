n = int(input())
out = [1] * (n + 1)
for i in range(2, n):
    for j in range(2 * i, n + 1, i):
        out[j] = i
print(' '.join(map(str,sorted(out[2:]))))