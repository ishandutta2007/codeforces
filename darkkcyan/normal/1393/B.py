from sys import stdin
maxn = 101010
n = int(stdin.readline())
cnt = [0] * maxn
has = [0] * 10
has[0] = maxn

def upd_has(pos, val):
    pos = min(pos, 8)
    for i in range(pos, -1, -1):
        has[i] += val

for i in map(int, stdin.readline().split()):
    upd_has(cnt[i], -1)
    cnt[i] += 1
    upd_has(cnt[i], 1)
    
q = int(stdin.readline())
for query in range(q):
    ch, num = stdin.readline().strip().split()
    num = int(num)
    sign = 1 if ch == '+' else -1
    upd_has(cnt[num], -1)
    cnt[num] += sign
    upd_has(cnt[num], 1)
    
    if has[8] > 0:
        print("YES")
        continue
    if has[6] > 0 and has[2] >= 2:
        print("YES")
        continue
    if has[4] > 0 and has[2] >= 3:
        print("YES")
        continue
    if has[4] >= 2:
        print("YES")
        continue
    print("NO")