import sys

n = int(input())

edges = set()

def add_edge(i,j):
    edges.add((min(i,j) + 1, max(i,j) + 1))

def query(i):
    print('?',i+1)
    sys.stdout.flush()
    l = list(map(int, input().split()))
    for j in range(n):
        if l[j] == 1:
            add_edge(i,j)
    return l

res = query(0)
odd = []
even = []
for i in range(1, n):
    if res[i] % 2:
        odd.append(i)
    else:
        even.append(i)

if len(odd) < len(even):
    smol = odd
else:
    smol = even

for v in smol:
    query(v)

print('!')
for a,b in edges:
    print(a,b)
sys.stdout.flush()