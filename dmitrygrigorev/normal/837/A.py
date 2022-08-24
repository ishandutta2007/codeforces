n = int(input())
s = input().split()
i = 0
for j in range(len(s)):
    ss = s[j]
    v = 0
    for k in range(len(s[j])):
        if s[j][k] < 'a':
            v += 1
    i = max(i, v)
print(i)