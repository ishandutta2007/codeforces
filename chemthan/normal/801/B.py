s = input()
t = input()
n = len(s)
for i in range(0, n):
    if s[i] < t[i]:
        print(-1)
        exit(0)
print(t)