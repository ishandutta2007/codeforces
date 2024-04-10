inp = input().split(' ')
change = {}
for x in range(int(inp[1])):
    a = input().split()
    if len(a[1])<len(a[0]):
        change[a[0]] = a[1]
    else:
        change[a[0]] = a[0]
b = input().split(' ')
out = ""
c = b.pop(0)
out = out + change[c]
for y in b:
    out = out + ' ' + change[y]
print(out)