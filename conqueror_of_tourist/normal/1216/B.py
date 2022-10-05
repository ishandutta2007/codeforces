n = int(input())
l = list(map(int,input().split()))
l2 = [(i,l[i]) for i in range(n)]
l3 = sorted(l2, key = lambda x: x[1])

out = 0
out2 = []
for i in range(n):
    nex = l3.pop()
    out += i * nex[1] + 1
    out2.append(str(nex[0] + 1))

print(out)
print(' '.join(out2))