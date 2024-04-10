n, m, k, x, y = list(map(int, input().split()))
prohod = (2 * n - 2) * m
if n == 1:
    prohod = m
last = k % prohod
minimum = k // prohod
maximum = (k // prohod) * 2
line = []
a1 = 10000000000000000000000000
a2 = -10000000000000000000000000
for i in range(n):
    if i == 0 or i == n-1:
        line += [minimum]
    else:
        line += [maximum]
ask = True
for i in range(n):
    if (last >= m):
        last -= m
        line[i] += 1
    else:
        if (last > 0):
            if (i == x - 1 and last < y):
                ask = False            
            line[i] += 1
            a1 = min(a1, line[i] - 1) 
            a2 = max(a2, line[i])
            last = 0
        else:
            a1 = min(a1, line[i]) 
            a2 = max(a2, line[i])            
    a2 = max(a2, line[i]) 
    a1 = min(a1, line[i])     
i = n - 2
while i > 0:
    if (last >= m):
        last -= m
        line[i] += 1
    else:
        if (last > 0):
            if (i == x - 1 and last < y):
                ask = False            
            line[i] += 1
            a1 = min(a1, line[i] - 1) 
            a2 = max(a2, line[i])  
            last = 0
        else:
            a1 = min(a1, line[i]) 
            a2 = max(a2, line[i])             
        break
    a2 = max(a2, line[i]) 
    a1 = min(a1, line[i]) 
    i -= 1
a3 = line[x - 1]
if not ask:
    a3 -= 1
print(a2, a1, a3)