n, k = map(int, input().split())

c = 0
nn = n
while nn > 0:
    nn//=k
    c+=1

#print(c)
curr = [0]*c
things = []
for i in range(n-1):
    things.append(tuple(curr))
    curr[0] += 1
    for i in range(c):
        if curr[i] == k:
            curr[i] = 0
            curr[i+1] += 1
        else:
            break
things.append(tuple(curr))
    
out = []
for i in range(n):
    for j in range(i + 1, n):
        for cc in range(c):
            if things[j][cc] > things[i][cc]:
                out.append(cc+1)
                break
print(max(out))
print(' '.join(map(str,out)))