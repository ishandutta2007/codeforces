def findfirst(s, t):
    return s.find(t)

def findlast(s, t):
    v = (s[::-1]).find(t[::-1])
    if v == -1:
        return -1
    else:
        return len(s) - v - len(t)

matcht = input()
x = input()
y = input()

canForward = False

a = findfirst(matcht, x)
b = findlast(matcht, y)

if a != -1 and b != -1 and a + len(x) <= b:
    canForward = True

c = findfirst(matcht[::-1], x)
d = findlast(matcht[::-1], y)

canBackward = False

if c != -1 and d != -1 and c + len(x) <= d:
    canBackward = True

if canForward and canBackward:
    print("both")
elif canForward:
    print("forward")
elif canBackward:
    print('backward')
else:
    print("fantasy")