t, n = list(map(int, input().split()))
l = list(map(int, input().split()))
q = max(1, l[n-1])
print(sum([(1 if int(i) >= q else 0)for i in l]))