from sys import stdin
s = stdin.readline().strip()
ans = 0
t = '1'
while len(t) < len(s) or (len(t) == len(s) and t < s):
    ans += 1
    t += '00'
print(ans)