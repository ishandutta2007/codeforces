import sys, io, os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
child = [[] for _ in range(n)]
par = [-1] + list(map(lambda x: int(x) - 1, input().split()))
for i in range(1, n):
    child[par[i]].append(i)
    
pop = list(map(int, input().split()))

end = [0] * n

stack = [0]
while stack:
    if len(child[stack[-1]]) == 0:
        v = stack.pop()
        
        if end[v] == 0:
            end[v] = 1
        
        if v:
            p = stack[-1]
            end[p] += end[v]
            pop[p] += pop[v]
            
        continue
    
    else:
        stack.append(child[stack[-1]].pop())
        
out = [(p + e - 1)//e for e, p in zip(end,pop)]
print(max(out))