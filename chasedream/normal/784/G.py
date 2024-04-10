str = input()
res = eval(str)

a = res // 100
b = res // 10 % 10
c = res % 10

def getans(x: int):
    for i in range(0, 48 + x):
        print('+', end = "")
    print('.>', end = "")

if a != 0:
    getans(a)
if b != 0:
    getans(b)
getans(c)