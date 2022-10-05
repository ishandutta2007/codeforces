t = int(input())
 
for _ in range(t):
    n = int(input())
    count = [0] * 200
    for v in map(int, input().split()):
        count[v] += 1 
    out = 0
    curr = 2
    for v in count:
        curr = min(curr, v)
        out += curr
    print(out)