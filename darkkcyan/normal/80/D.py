
def calArea(a, b):
    if a <= 4 * b:
        return a * min(b, a / 4) / 2
    return b * b * 2 + (a - 4 * b) * b 

for _ in range(int(input())):
    a, b = map(int, input().split())
    if b == 0:
        print(1)
    elif a == 0:
        print(0.5)
    else:
        print("{:.8f}".format(calArea(a, b) / (2 * a * b) + 0.5))