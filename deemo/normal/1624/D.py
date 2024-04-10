te = int(input())
while te > 0:
    te -= 1
    n, k = map(int, input().split())
    s = input()
    cnt = [0] * 26
    for c in s:
        cnt[ord(c)-97] += 1

    ev = 0
    od = 0
    for x in cnt:
        ev += x // 2
        od += x % 2

    for ln in range(n // k, 0, -1):
        tev = ev
        tod = od
        tev -= k * (ln // 2)
        if tev < 0:
            continue
        if ln % 2 == 0 or tev * 2 + tod >= k:
            print(ln)
            break