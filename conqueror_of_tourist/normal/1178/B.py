s = input()
n = len(s)

out = 0
wCount = 0
oPlace = []
for i in range(n-1):
    if s[i] == 'o':
        oPlace.append(wCount)
    elif s[i] == 'v' and s[i+1] == 'v':
        wCount += 1

print(sum(map(lambda x: x*(wCount-x),oPlace)))