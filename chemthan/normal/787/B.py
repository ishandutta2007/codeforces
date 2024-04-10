n, m = map(int, list(input().split()))
for i in range(0, m):
    ar = list(input().split())
    st = set(int(ar[j]) for j in range(1, len(ar)))
    found = False;
    for x in st:
        if -x in st:
            found = True
    if found == False:
        print("YES")
        exit(0)
print("NO")

exit(0)