n = int(input())

s = input().strip()

out = 0


t = set()
for c in s:
    if c == 'R':
        if 'L' in t:
            t = set()
            out += 1
    elif c == 'L':
        if 'R' in t:
            t = set()
            out += 1
    elif c == 'U':
        if 'D' in t:
            t = set()
            out += 1
    elif c == 'D':
        if 'U' in t:
            t = set()
            out += 1

    t.add(c)

print(out + 1)