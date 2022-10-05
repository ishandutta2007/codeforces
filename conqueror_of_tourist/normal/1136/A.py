n = int(input())
l = []
for i in range(n):
    l.append(list(map(int, input().split())))
page = int(input())

out = 0
for ch in l:
    if ch[-1] >= page:
        out += 1

print(out)