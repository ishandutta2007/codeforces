n = int(input())
s = input()

l = []
for i in range(26):
    l.append([0])
    
for i in range(n):
    c = s[i]
    l[ord(c)-ord('a')].append(i+1)

m = int(input())
for friend in range(m):
    s2 = input()
    count = [0]*26
    for c in s2:
        count[ord(c)-97] += 1

    out = 0
    for i in range(26):
        out = max(out, l[i][count[i]])

    print(out)