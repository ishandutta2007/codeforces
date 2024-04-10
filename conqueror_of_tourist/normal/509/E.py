song = input()
le = len(song)
su = 0
for x in range(1,le+1):
    su += 1/x
l = [0]*le
l[0] = su
diff = su
for x in range(1,int((le+1)/2)):
    diff -= (1/x + 1/(le+1-x))
    l[x] = l[x-1] + diff
for x in range(int((le+1)/2),le):
    l[x] = l[le-1-x]


ans = 0
for x in range(le):
    let = song[x]
    if let in ['A','E','I','O','U','Y']:
        ans += l[x]

print(ans)