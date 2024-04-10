inp = input()
inp = inp.split(' ')
a = int(inp[0])
b = int(inp[1])
c = int(inp[2])
if a%c == 0:
    r1 = a/c
else:
    r1 = int(a/c) + 1
if b%c == 0:
    r2 = b/c
else:
    r2 = int(b/c) + 1
print(int(r1*r2))