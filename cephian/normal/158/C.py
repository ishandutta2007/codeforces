# your code goes here
import re
n = int(input())

dir = []

def pr():
    ans = ""
    for f in dir:
        if f != '':
            ans += '/' + f
    print(ans + '/')

for _ in range(n):
    s = input()
    if s == 'pwd':
        pr()
        continue
    if ' /' in s:
        del dir[:]
    r = re.compile('/| ')
    lst = r.split(s)
    for li in lst[1:]:
        if li == '..':
            del dir[-1]
        else:
            dir.append(li)