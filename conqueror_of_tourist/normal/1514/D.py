import sys
input = sys.stdin.readline

n, q = map(int, input().split())

counts = [0] * (n + 1)
c_amt = [0] * (n + 3); c_amt[0] = n + 1
max_count = 0
moves = 0

def add(x):
    global max_count, moves
    moves += 1
    v = l[x]
    c_amt[counts[v]] -= 1
    counts[v] += 1
    c_amt[counts[v]] += 1
    max_count = max(counts[v], max_count)

def remove(x):
    global max_count, moves
    moves += 1
    v = l[x]
    c_amt[counts[v]] -= 1
    if max_count == counts[v] and c_amt[counts[v]] == 0:
        max_count -= 1
    counts[v] -= 1
    c_amt[counts[v]] += 1
    

l = list(map(int, input().split()))
left = 0
right = -1

out = [0] * q
queries = []
for i in range(q):
    ll, rr = map(int, input().split())
    queries.append((ll-1,rr-1,i))
k = 547
queries.sort(key = lambda x: 2 * n * (x[0]//k) + (x[1] * ((-1) ** (x[0]//k))))

for ll, rr, i in queries:
    while right < rr:
        add(right + 1)
        right += 1
    while right > rr:
        remove(right)
        right -= 1
    while left > ll:
        add(left - 1)
        left -= 1
    while left < ll:
        remove(left)
        left += 1
    sz = rr - ll + 1
    top = max_count
    other = sz-top
    out[i] = max(1, top-other)

print('\n'.join(map(str,out)))