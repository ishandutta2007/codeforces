n = int(input())

desc = []

for _ in range(n):
    l = list(map(int, input().split()))[1:]

    asc = False
    for i in range(len(l) - 1):
        if l[i] < l[i + 1]:
            asc = True
            break

    if not asc:
        desc.append((l[-1], l[0]))

out = n * n

#Do Stuff
d = len(desc)

desc.sort()
desc2 = sorted(desc, key = lambda x:  (x[1], x[0]))

count = 0
for _, m in desc2:
    while count < d:
        if desc[count][0] >= m:
            break
        count += 1
    out -= (d - count)
        

#End Stuff

print(out)