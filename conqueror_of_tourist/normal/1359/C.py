import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    h, c, t = map(int, input().split())
    if h + c >= 2 * t:
        print(2)
    else:
        diff2 = 2*t - (h + c)
        hDiff2 = 2*h - (h + c)

        kDown = (hDiff2//diff2 - 1)//2
        kUp = kDown + 1
        diffDown = abs(diff2 - hDiff2/(2 * kDown + 1))
        diffUp = abs(diff2 - hDiff2/(2 * kUp + 1))
        if diffDown <= diffUp:
            print(2 * kDown + 1)
        else:
            print(2 * kDown + 3)