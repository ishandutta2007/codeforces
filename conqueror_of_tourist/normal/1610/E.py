import sys, bisect
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    poss = []
    for i in range(n):
        if i > 0 and a[i] == a[i-1]:
            continue

        ind = i
        ct = 1
        while ind + 1 < i and a[ind + 1] == a[i]:
            ind += 1
            ct += 1

        while ind < n:
            nind = bisect.bisect_left(a, 2 * a[ind] - a[i], ind + 1)
            if nind < n:
                ind = nind
                ct += 1
            else:
                break

        poss.append(ct)
    out.append(n - max(poss))
    #print(poss)
print('\n'.join(map(str,out)))