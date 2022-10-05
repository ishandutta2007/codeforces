import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input()
    last = '1'
    isOne = False
    start = 0
    for c in s:
        if c == '0' and last != '0':
            start += 1
        last = c
        if c == '1':
            isOne = True

    poss = [2, start]
    if not isOne:
        poss.append(1)
    print(min(poss))