d = [0, 0, 0]

for c in raw_input():
    if c == 'Q':
        d[2] += d[1]
        d[0] += 1
    elif c == 'A':
        d[1] += d[0]

print d[2]