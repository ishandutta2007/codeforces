n, p = map(int,input().split())
l = list(map(int,input().split()))
l.sort()

smalls = [l[i] - i for i in range(n)]
tols = [l[i]-i+p-1 for i in range(p-1,n)]
smol = max(smalls)
tol = min(tols)

out = list(range(smol,tol))
print(len(out))
print(' '.join(map(str,out)))