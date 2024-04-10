n, m, k = map(int, input().split())

out = []
for i in range(n - 1):
    out.append('D')
for i in range(m - 1):
    out.append('L')

curr = 'U'
for i in range(m):
    out.append(curr * (n-1))
    out.append('R')
    if curr == 'U':
        curr = 'D'
    else:
        curr = 'U'

s = ''.join(out)
print(len(s))
print(s)