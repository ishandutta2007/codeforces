import sys
input = sys.stdin.readline

n = int(input())

xor = [0]
find = [0,0,0,0]
for i in range(1,n):
    print('XOR',1,i+1)
    sys.stdout.flush()
    v = int(input())
    if v == -1:
        exit()
    xor.append(v)
    if v < 4:
        find[v] = i
        
if find[1] != 0 and find[2] != 0:
    print('AND',1,1+find[1])
    sys.stdout.flush()
    o1 = int(input())
    if o1 == -1:
        exit()
        
    print('AND',1,1+find[2])
    sys.stdout.flush()
    o2 = int(input())
    
    val = o1 | o2
else:
    rev = [-1] * n
    for i in range(n):
        if rev[xor[i]] == -1:
            rev[xor[i]] = i
        else:
            j = rev[xor[i]]
            break
    
    assert xor[i] == xor[j]
        
    print('AND',i+1,j+1)
    sys.stdout.flush()
    o = int(input())
    
    val = o ^ xor[i]

out = ['!']
for v in xor:
    out.append(v ^ val)
print(' '.join(map(str,out)))
sys.stdout.flush()