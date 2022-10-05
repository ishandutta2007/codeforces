import sys
input = sys.stdin.readline
outL = []
t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    
    ct = 0
    for c in s:
        if c == '*':
            ct += 1
    
    out = 0
    ct2 = 0
    for c in s:
        if c == '*':
            ct2 += 1
        else:
            out += min(ct2, ct-ct2)
        
    outL.append(out)
print('\n'.join(map(str,outL)))