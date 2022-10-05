n = int(input())
s = input()
t = input()

curr = 0
currs = []
for i in range(n):
    if s[i] == '1':
        curr += 1
    if t[i] == '1':
        curr -= 1
    currs.append(curr)

if curr != 0:
    print(-1)
else:
    print(max(currs)-min(currs))