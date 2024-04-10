n, k = list(map(int, input().split()))
line = list(map(int, input().split()))
s = 0
for i in range(len(line) - 1):
    if line[i] + line[i + 1] < k:
        m =  k - line[i] - line[i + 1]
        line[i + 1] += k - line[i] - line[i + 1]
        s += m
print(s)
print(" ".join(map(str, line)))