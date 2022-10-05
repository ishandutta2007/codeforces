import math

T = int(input())
for _ in range(T):
    n = int(input())
    diags = 1/math.sin(math.pi/2/n)
    print(diags * math.cos(math.pi/4/n))