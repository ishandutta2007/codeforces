n = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))
check = p[:]

out = []
def swap(a,b):
    out.append(str(a+1)+' '+str(b+1))
    check[a], check[b] = -check[b], -check[a]

vis = [False] * n
head = []
for i in range(n):
    if not vis[i]:
        head.append(i)
        vis[i] = True
        curr = i
        while p[curr] != i:
            curr = p[curr]
            vis[curr] = True

while len(head) >= 2:
    a = head.pop()
    b = head.pop()

    swap(a,b)
    curra = p[a]
    while curra != a:
        swap(b, curra)
        curra = p[curra]
    currb = p[b]
    while currb != b:
        swap(a, currb)
        currb = p[currb]
    swap(a,b)

if len(head) == 1:
    a = head[0]
    if p[a] == a:
        pass
    elif p[p[a]] == a:
        a1 = a
        a2 = p[a]
        a3 = b
        swap(a2, a3)
        swap(a1, a3)
        swap(a2, a3)
    else:
        l = [a, p[a]]
        while p[l[-1]] != a:
            l.append(p[l[-1]])
        k = len(l)
        swap(l[0], l[1])
        for i in range(2, k - 1):
            swap(l[0], l[i])
        swap(l[1], l[k - 1])
        swap(l[0], l[k - 1])
        swap(l[0], l[1])

assert check == list(range(n))
assert len(out) <= n + 1

print(len(out))
print('\n'.join(out))