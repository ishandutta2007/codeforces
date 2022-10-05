import sys
input = sys.stdin.readline

want = 'abacaba'

T = int(input())
for _ in range(T):
    n = int(input())
    s = input().strip()
    l = list(s)

    for i in range(n - 6):
        ll = l[:]
        works = True
        for c in range(7):
            if ll[c + i] == want[c] or ll[c+i] == '?':
                ll[c + i] = want[c]
            else:
                works = False
        if works:
            for j in range(n - 6):
                if i != j and ll[j:j+7] == list(want):
                    break
            else:
                print('Yes')
                for j in range(n):
                    if ll[j] == '?':
                        ll[j] = 'd'
                print(''.join(ll))
                break
    else:
        print('No')