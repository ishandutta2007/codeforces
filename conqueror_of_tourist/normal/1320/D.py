import sys
input = sys.stdin.readline

MOD = 987654103

n = int(input())
t = input()

place = []
f1 = []
e1 = []

s = []
curr = 0
count1 = 0
for i in range(n):
    c = t[i]
    if c == '0':
        if count1:
            e1.append(i - 1)
            if count1 & 1:
                s.append(1)
                curr += 1
                e1.append(-1)
                f1.append(-1)
            count1 = 0
        else:
            f1.append(-1)
            e1.append(-1)

        place.append(curr)
        curr += 1
        s.append(0)
    else:
        if count1 == 0:
            f1.append(i)
        count1 += 1
        place.append(curr)

if count1:
    if count1 & 1:
        s.append(1)
    else:
        s.append(0)
    curr += 1
    e1.append(n - 1)

    e1.append(-1)
    f1.append(-1)
place.append(curr)

pref = [0]
val = 0
for i in s:
    val *= 3
    val += i + 1
    val %= MOD
    pref.append(val)
        

q = int(input())
out = []
for _ in range(q):
    l1, l2, leng = map(int, input().split())
    l1 -= 1
    l2 -= 1

    starts = (l1, l2)
    hashes = []
    for start in starts:
        end = start + leng - 1

        smap = place[start]
        emap = place[end]
        if t[end] == '1':
            emap -= 1
        if s[smap] == 1:
            smap += 1

        prep = False
        app = False

        if t[start] == '1':
            last = e1[place[start]]
            last = min(last, end)
            count = last - start + 1
            if count % 2:
                prep = True
        if t[end] == '1':
            first = f1[place[end]]
            first = max(first, start)
            count = end - first + 1
            if count % 2:
                app = True

        preHash = 0
        length = 0
        if smap <= emap:
            length = emap - smap + 1
            preHash = pref[emap + 1]
            preHash -= pref[smap] * pow(3, emap - smap + 1, MOD)
            preHash %= MOD


        if length == 0 and prep and app:
            app = False

        #print(preHash, prep, app, length)
        if prep:
            preHash += pow(3, length, MOD) * 2
            length += 1
        if app:
            preHash *= 3
            preHash += 2
        #print(preHash)

        preHash %= MOD
        hashes.append(preHash)
        
    if hashes[0] == hashes[1]:
        out.append('Yes')
    else:
        out.append('No')

print('\n'.join(out))