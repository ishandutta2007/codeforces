t = int(input())
out = []
for _ in range(t):
    n = int(input())//2
    if n%2:
        out.append('NO')
    else:
        out.append('YES')
        l = []
        l2 = []
        for i in range(n//2):
            l.append(6*i+2)
            l.append(6*i+4)
            l2.append(6*i+1)
            l2.append(6*i+5)
        out.append(' '.join(map(str,l))+' '+' '.join(map(str,l2)))
            
print(*out,sep='\n')