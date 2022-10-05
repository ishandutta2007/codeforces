import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    l = list(map(int, input().split()))
    
    stack = []
    out = [-1] * n
    curr = 0
    works = True
    for i in range(n):
        while stack and stack[-1][0] == i:
            _, j = stack.pop()
            curr += 1
            out[j] = curr
        
        nex = l[i] - 1
        if nex == -2:
            curr += 1
            out[i] = curr
        else:
            if stack and nex > stack[-1][0]:
                works = False
            else:
                stack.append((nex, i))
    
    while stack:
        _, j = stack.pop()
        curr += 1
        out[j] = curr
    
    if works:
        print(*out)
    else:
        print(-1)