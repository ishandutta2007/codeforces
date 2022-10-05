n, m = list(map(int, input().split()))
line = list(map(int, input().split()))

pairs = set()
for i in range(m):
    a, b = list(map(int, input().split()))
    pairs.add((a,b))

req = [line.pop()]

out = 0
while line != []:
    nex = line.pop()
    works = True
    for pers in req:
        if not (nex, pers) in pairs:
            works = False
            break
    if works:
        out += 1
    else:
        req.append(nex)

print(out)