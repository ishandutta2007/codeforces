n = float(input())
s = 0
for x in range(50):
    s += (x**2 + x)/2
    if s>n:
        print(x-1)
        break