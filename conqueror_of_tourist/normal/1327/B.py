import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    used = set()
    lonely = []
    for d in range(1, n + 1):
        l = list(map(int, input().split()))[1:]

        for k in l:
            if k not in used:
                used.add(k)
                break
        else:
            lonely.append(d)
    if len(lonely):
        print('IMPROVE')
        k = 1
        while k in used:
            k += 1
        print(lonely[0], k)
    else:
        print('OPTIMAL')