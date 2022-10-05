n = int(input())
l = map(int, input().split())

stack = []
for v in l:
    currVal = v
    currSize = 1
    div = v
    
    while stack:
        nex, nexS, nDiv = stack[-1]

        if div < nDiv:
            currSize += nexS
            currVal += nex
            stack.pop()

            div = currVal / currSize
        else:
            break
    stack.append((currVal, currSize, div))

out = []
for a, b, d in stack:
    thingy = str(d)
    for _ in range(b):
        out.append(thingy)
        
print('\n'.join(out))