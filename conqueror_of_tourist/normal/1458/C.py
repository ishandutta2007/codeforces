import sys,io,os;input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t = int(input())
out = []
for _ in range(t):
    n, m = map(int, input().split())
    MAT = [list(map(int, input().split())) for i in range(n)]
    
    dx = 0
    dy = 0
    order = [0,1,2]
    d = [0,0,0]
    s = input()
    
    for c in s:
        if c == ord('R'):
            d[1] += 1
        elif c == ord('L'):
            d[1] -= 1
        elif c == ord('D'):
            d[0] += 1
        elif c == ord('U'):
            d[0] -= 1
        elif c == ord('I'):
            order[1],order[2]=order[2],order[1]
            d[1],d[2]=d[2],d[1]
        elif c == ord('C'):
            order[0],order[2]=order[2],order[0]
            d[0],d[2]=d[2],d[0]

    om = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(n):
            r, c, v = i, j, MAT[i][j] - 1
            trip = [-1,-1,-1]
            
            for u in range(3):
                trip[u] = [r,c,v][order[u]]
                trip[u] += d[u]
                trip[u] %= n
            
            om[trip[0]][trip[1]] = trip[2] + 1
            
    for line in om:
        out.append(' '.join(map(str,line)))
        
print('\n'.join(out))