import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    curr = 0
    vals = []
    neg = []
    for i in range(2 * n):
        c = s[i]
        if c == '(':
            curr += 1
        elif c == ')':
            curr -= 1

        vals.append(curr)
        if curr < 0:
            neg.append(i)

    big = max(vals)
    maxes = []
    for i in range(2 * n):
        if vals[i] == big:
            maxes.append(i)

    if len(neg) == 0:
        out.append(0)
    elif max(neg) < max(maxes):
        out.append(1)
        out.append('1 '+str(max(maxes) + 1))
    elif min(neg) > min(maxes):
        out.append(1)
        out.append(str(min(maxes) + 2) + ' ' + str(2 * n))
    else:
        bestL = 0
        lP = -1
        for i in range(min(neg)):
            if vals[i] > bestL:
                bestL = vals[i]
                lP = i

        bestR = -1
        rP = 2 * n
        for i in range(max(neg), 2 * n):
            if vals[i] > bestR:
                bestR = vals[i]
                rP = i
                
        if bestL + bestR >= big:
            out.append(1)
            out.append(str(lP + 2) + ' ' + str(rP + 1))
        else:
            out.append(2)
            v = maxes[0]
            out.append('1 '+str(v + 1))
            out.append(str(v + 2) + ' ' + str(2 * n))

print('\n'.join(map(str, out)))