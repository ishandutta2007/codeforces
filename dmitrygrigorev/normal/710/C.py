n = int(input())
m = n ** 2
ch = []
nech = []
for i in range(1, m + 1):
    if i % 2 == 0:
        ch += [i]
    else:
        nech += [i]
line = []  
for i in range(n):
    line += [[]]
for i in range(n):
    for j in range(n):
        if i < n // 2:
            if j < n // 2 - i or j > n//2 + i:
                line[i] += [ch[-1]]
                ch.pop()
            else:
                line[i] += [nech[-1]]
                nech.pop()
        elif i == n // 2:
            line[i] += [nech[-1]]
            nech.pop()
        else:
            i1 = n - i - 1
            if j < n // 2 - i1 or j > n//2 + i1:
                line[i] += [ch[-1]]
                ch.pop()
            else:
                line[i] += [nech[-1]]
                nech.pop()         
for i in range(n):
    print(" ".join(map(str, line[i])))