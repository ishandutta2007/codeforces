import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    out = []

    done = False
    while not done:
        seen = [False] * (n + 1)
        loc = [-1] * (n + 1)
        
        for i in range(n):
            v = l[i]
            loc[v] = i
            seen[v] = True

        fix = False
        for m in range(n):
            if not seen[m]:
                fix = True
                break

        if fix:
            out.append(m + 1)
            l[m] = m
        else:
            for i in range(n - 1):
                if l[i] != i:
                    j = loc[i]
                    out.append(j+1)
                    l[j]=n
                    break
            else:
                done = True

    print(len(out))
    print(' '.join(map(str,out)))