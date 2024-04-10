import sys
input = sys.stdin.readline

n = int(input())
c1 = []
c2 = []

for i in range(n):
    for j in range(n):
        if (i + j) % 2 == 0:
            c1.append((i+1,j+1))
        else:
            c2.append((i+1,j+1))

for turn in range(n * n):
    a = int(input())

    color = 1 if a != 1 else 2
    alt = 6 - a - color

    curr = c1 if color == 1 else c2
    other = c2 if color == 1 else c1

    if curr:
        x, y = curr.pop()
        print(color, x, y)
    else:
        x, y = other.pop()
        print(alt, x, y)
    sys.stdout.flush()