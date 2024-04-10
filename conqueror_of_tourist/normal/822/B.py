input()
s = input()
t = input()
l = []
for i in range(26):
    l.append([])
for i in range(len(s)):
    l[ord(s[i])-ord('a')].append(i)
l2 = []
for i in range(len(t)):
    l2.append([])
l3 = [0]*len(t)
for i in range(len(t)):
    c = t[i]
    pos = l[ord(c)-ord('a')]
    for p in pos:
        start = i-p
        if len(t)-len(s) >= start >= 0:
            l3[start] += 1
            l2[start].append(p)
best = max(l3)
posb = l3.index(best)
print(len(s)-best)
things = l2[posb]
k = []
for i in range(len(s)):
    if not i in things:
        k.append(str(i+1))
print(' '.join(k))