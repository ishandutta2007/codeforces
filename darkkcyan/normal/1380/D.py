from sys import exit 

n, m = map(int, input().split())
x, k, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

pos = [0] * (n + 1)
for i, val in enumerate(a):
    pos[val] = i

def process(l, r):
    ans = 0
    u = a[l] if l >= 0 else 0
    v = a[r] if r < n else 0
    
    cnt_big = 0
    mx = max(u, v)
    for i in range(l + 1, r):
        if mx < a[i]:
            cnt_big += 1
    dist = r - l - 1
    if cnt_big > 0 and dist < k:
        print("-1")
        exit(0)
        
    if y * k < x:
        if cnt_big > 0:
            dist -= k
            ans += x
        ans += dist * y
    else:
        ans = (dist // k) * x + (dist % k) * y
    # print(l, r, ans) 
    return ans
    
ans = process(-1, pos[b[0]]) + process(pos[b[-1]], n)
for u, v in zip(b, b[1:]):
    if pos[u] > pos[v]:
        print("-1")
        exit(0)
    ans += process(pos[u], pos[v])
    
print(ans)