n, m = map(int, input().split())

out = [[] for i in range(n)]
for i in range(n):
    out[i].append((i + 1, i + 1))
    
curr = n + 100
for j in range(m):
    a, b = map(int, input().split())
    out[a-1].append((a,curr))
    out[b-1].append((b,curr))
    curr += 1

for l in out:
    print(len(l))
    for a, b in l:
        print(a,b)