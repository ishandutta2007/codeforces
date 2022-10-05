import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    lengths = []
    curr = s[0]
    currLen = 0
    for c in s:
        if c == curr:
            currLen += 1
        else:
            lengths.append(currLen)
            currLen = 1
            curr = c
    if currLen < n and s[0] == s[-1]:
        lengths[0] += currLen
    else:
        lengths.append(currLen)


    out = 0
    if len(lengths) == 1 and n >= 3:
        out = 1
        lengths[0] -= 1
        lengths.append(1)
        

    for v in lengths:
        out += v // 3
    print(out)