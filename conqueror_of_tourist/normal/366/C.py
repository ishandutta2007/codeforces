n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(lambda x: int(x) * k, input().split()))

pos = [0] * 10 ** 5
neg = [0] * 10 ** 5

pos[0] = 1
neg[0] = 1

base = 0

for i in range(n):
    d = a[i] - b[i]
    if d > 0:
        for j in range(10 ** 5-1,-1,-1):
            if pos[j]:
                if j + d < 10 ** 5:
                    pos[j+d] = max(pos[j+d],pos[j]+a[i])
    elif d < 0:
        for j in range(10 ** 5-1,-1,-1):
            if neg[j]:
                if j - d < 10 ** 5:
                    neg[j-d] = max(neg[j-d],neg[j]+a[i])
    else:
        base += a[i]

best = 0
for i in range(10 ** 5):
    if pos[i] and neg[i]:
        best = max(best,pos[i] + neg[i])
best -= 2
best += base
if best:
    print(best)
else:
    print(-1)