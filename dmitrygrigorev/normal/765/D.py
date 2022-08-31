n = int(input())
line = list(map(int, input().split()))
h = []
sets = set()
mm = dict()
out = False
for i in range(len(line)):
    element = line[i]
    if line[element - 1] != element:
        print(-1)
        out = True
        break
    else:
        if element not in sets:
            h += [element]
            mm[element] = len(h) - 1
            sets.add(element)
if not out:
    g = []
    for i in range(n):
        element = line[i]
        index = mm[element]
        g += [index + 1]
    if not out:
        print(len(h))
        print(" ".join(map(str, g)))
        print(" ".join(map(str, h)))