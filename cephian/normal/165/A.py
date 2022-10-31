def rel(x1, y1, x2, y2):
    if y1 == y2:
        if x1 < x2:
            return 1
        return 2
    if x1 == x2:
        if y1 < y2:
            return 4
        return 8
    return 0
    
n = int(input())
x = []
y = []
mask = [0] * n
for _ in range(n):
    inp = input().split()
    x.append(int(inp[0]))
    y.append(int(inp[1]))
    
for i in range(n):
    for j in range(n):
        if i == j:
            continue
        mask[i] |= rel(x[i], y[i], x[j], y[j])
ans = 0
for m in mask:
    if m == 15:
        ans += 1
print(ans)