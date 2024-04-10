ri = lambda: map(int, raw_input().split())
n, x = ri()
a = x
for i in ri():
    if i < x:
        a -= 1
    elif i == x:
        a += 1
print a