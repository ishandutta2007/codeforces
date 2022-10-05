n = int(input())
l = list(map(int, input().split()))

inv = 0
out = 0
mult = 1
for i in range(32):
    curr = dict()
    opp = 0
    same = 0

    for v in l:
        if v ^ 1 in curr:
            if v & 1:
                opp += curr[v ^ 1]
            else:
                same += curr[v ^ 1]
            
        if v not in curr:
            curr[v] = 0
        curr[v] += 1

    for i in range(n):
        l[i] >>= 1

    if same <= opp:
        inv += same
    else:
        inv += opp
        out += mult
    mult *= 2
print(inv, out)