chars = []
typ = []

s = input()
for c in s:
    if c == '?':
        typ[-1] = 1
    elif c == '*':
        typ[-1] = 2
    else:
        chars.append(c)
        typ.append(0)

typCount = [0,0,0]

for i in typ:
    typCount[i] += 1

want = int(input())

for i in range(len(chars)): 
    if typCount[0] >= want:
        break

    if typ[i] == 1:
        typ[i] = 0
        typCount[0] += 1

if typCount[0] > want:
    print('Impossible')
else:
    if typCount[2] == 0 and typCount[0] < want:
        print('Impossible')
    else:
        if typCount[2] > 0:
            i = typ.index(2)
            chars[i] *= (want-typCount[0])
            typ[i] = 0

        out = ''
        for i in range(len(chars)):
            if typ[i] == 0:
                out += chars[i]

        print(out)