A, B, C, D = map(int, input().split())

out = 0
for s in range(A + B, B + C + 1):
    xSmall = max(A, s - C)
    xBig = min(B, s - B)
    count = xBig - xSmall + 1
    if count < 0:
        continue
    
    zCount = max(0, min(s - 1,D) - C + 1)
    out += count * zCount
print(out)