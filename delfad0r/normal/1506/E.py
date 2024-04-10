from sys import stdin, stdout
 
def solve():
    n = int(input())
    q = [int(x) for x in stdin.readline().split()]
    amin = []
    used = [False for _ in range(n + 1)]
    l = 1
    for i in range(n):
        if i == 0 or q[i] > q[i - 1]:
            amin.append(q[i])
            used[q[i]] = True
        else:
            while used[l]:
                l += 1
            amin.append(l)
            l += 1
    amax = []
    l = 1
    z = []
    for i in range(n):
        if i == 0 or q[i] > q[i - 1]:
            while l <= q[i]:
                z.append(l)
                l += 1
        amax.append(z.pop())
    stdout.write(' '.join(map(str, amin)) + '\n')
    stdout.write(' '.join(map(str, amax)) + '\n')
    
    
 
t = int(input())
for _ in range(t):
    solve()