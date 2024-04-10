n = int(input())
d = {
    'A' : 10**8,
    'B' : 10**8,
    'C' : 10**8,
    'AB' : 10**8,
    'AC' : 10**8,
    'BC' : 10**8,
    'ABC' : 10**8
}
for i in range(n):
    x, s = input().split()[:2]
    x = int(x)
    s = ''.join(sorted(s))
    d[s] = min(x, d[s])
ans = min(
    d['A'] + d['B'] + d['C'],
    d['A'] + d['BC'],
    d['B'] + d['AC'],
    d['C'] + d['AB'],
    d['AB'] + d['BC'],
    d['AB'] + d['AC'],
    d['BC'] + d['AC'],
    d['ABC']
)
if ans == 10**8:
    print(-1)
else:
    print(ans)