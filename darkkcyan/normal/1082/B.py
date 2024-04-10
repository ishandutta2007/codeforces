from sys import exit
n = int(input())
s = input()
cntg = s.count('G')
if cntg == 0:
    print(0)
    exit(0)
    
a = [[s[0], 1]]
for prev, cur in zip(s[0:], s[1:]):
    if cur != prev:
        a.append([cur, 1])
    else:
        a[-1][1] += 1
ans = max(i[1] + (1 if i[1] < cntg else 0) for i in a if i[0] == 'G')
for prev, cur, nxt in zip(a[0:], a[1:], a[2:]):
    if cur[0] == 'G':
        continue
    if cur[1] != 1:
        continue
    t = prev[1] + nxt[1]
    ans = max(ans, t + (1 if t < cntg else 0))

print(ans)