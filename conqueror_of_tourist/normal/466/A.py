inp = input()
inp = inp.split(' ')
n = int(inp[0])
m = int(inp[1])
a = int(inp[2])
b = int(inp[3])
if b/m >= a:
    print(a*n)
else:
    out = b * int(n/m)
    n -= m * int(n/m)
    out += min(a*n,b)
    print(out)