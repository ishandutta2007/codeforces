ri = lambda: map(int, raw_input().split())
n, k = ri()
s = 0
for i, x in enumerate(ri()):
    s += x
    delta = min(s, 8)
    s -= delta
    k -= delta
    if k <= 0:
        print i + 1
        quit()
print -1