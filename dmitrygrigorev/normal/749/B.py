x1, y1 = list(map(int, input().split()))
x2, y2 = list(map(int, input().split()))
x3, y3 = list(map(int, input().split()))
line = []
x41 = x3 - (x2 - x1)
y41 = y3 - (y2 - y1)
line += [[x41, y41]]
x41 = x3 - (x1 - x2)
y41 = y3 - (y1 - y2)
line += [[x41, y41]]
x41 = x1 - (x2 - x3)
y41 = y1 - (y2 - y3)
line += [[x41, y41]]
x41 = x1 - (x3 - x2)
y41 = y1 - (y3 - y2)
line += [[x41, y41]]
x41 = x2 - (x1 - x3)
y41 = y2 - (y1 - y3)
line += [[x41, y41]]
x41 = x2 - (x3 - x1)
y41 = y2 - (y3 - y1)
line += [[x41, y41]]
line1 = [line[0]]
for i in range(1, 5):
    good = False
    for j in range(len(line1)):
        if line[i] == line1[j]:
            good = True
    if not good:
        line1 += [line[i]]
print(len(line1))
for i in range(len(line1)):
    print(" ".join(map(str, line1[i])))