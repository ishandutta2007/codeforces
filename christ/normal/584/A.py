n,t = map(int,input().split())
cur = t
if len(str(cur)) > n:
    print(-1)
    exit(0)
pw = 2**400
while pw:
    if len(str(pw*cur)) <= n:
        cur *= pw
    pw>>=1
print(cur)