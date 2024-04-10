import sys
input = sys.stdin.readline

n, m = map(int, input().split())
p = list(map(int, input().split()))

BLOCK_LENGTH = 410
block = [i//BLOCK_LENGTH for i in range(n)]

jumps = [0] * n
end = [0] * n

for i in range(n - 1, -1, -1):
    nex = i + p[i]
    if nex >= n:
        jumps[i] = 1
        end[i] = i + n
    elif block[nex] > block[i]:
        jumps[i] = 1
        end[i] = nex
    else:
        jumps[i] = jumps[nex] + 1
        end[i] = end[nex]
        
out = []
for _ in range(m):
    #print(jumps)
    #print(end)
    #print(block)
    s = input().strip()
    if s[0] == '0':
        _,a,b = s.split()
        a = int(a) - 1
        b = int(b)
        
        p[a] = b
        i = a
        while i >= 0 and block[i] == block[a]:
            nex = i + p[i]
            if nex >= n:
                jumps[i] = 1
                end[i] = i + n
            elif block[nex] > block[i]:
                jumps[i] = 1
                end[i] = nex
            else:
                jumps[i] = jumps[nex] + 1
                end[i] = end[nex]
            i -= 1
    else:
        _,a = s.split()
        curr = int(a) - 1
        jmp = 0
        while curr < n:
            jmp += jumps[curr]
            curr = end[curr]
        out.append(str(curr - n + 1)+' '+str(jmp))
print('\n'.join(out))