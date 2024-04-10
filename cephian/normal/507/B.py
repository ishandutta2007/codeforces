from math import ceil
from math import sqrt
def mag(x, y):
    return sqrt(x * x + y * y)

inp = input().split()

dist = mag(int(inp[1]) - int(inp[3]), int(inp[2]) - int(inp[4]))
print(ceil(dist/(2*int(inp[0]))))