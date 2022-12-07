s = input()
d = s
n = len(s)
for i in range(len(s)):
    d += s[n-1-i]
print(d)