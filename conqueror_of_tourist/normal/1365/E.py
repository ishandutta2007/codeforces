n = int(input())
l = list(map(int, input().split()))


best = 0
for i in range(n):
    for j in range(i, n):
        for k in range(j, n):
            best = max(best, l[i] | l[j] | l[k])
print(best)