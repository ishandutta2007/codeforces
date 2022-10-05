N, D = map(int, input().split())
P = list(map(int, input().split()))

P.sort(reverse = True)

ct = 0
tot = 0
for v in P:
    need = (D + v)//v
    tot += need
    if tot <= N:
        ct += 1
print(ct)