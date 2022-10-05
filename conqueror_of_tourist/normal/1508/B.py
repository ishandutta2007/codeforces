import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    k -= 1
    out = []
    curr = [1]
    todo = []
    for i in range(n - 1):
        todo.append(k % 2)
        k//=2
    todo.reverse()
    for i in range(n - 1):
        if todo[i]:
            curr.append(i + 2)
        else:
            while curr:
                out.append(curr.pop())
            curr.append(i + 2)
    while curr:
        out.append(curr.pop())
    if k == 0:
        print(' '.join(map(str,out)))
    else:
        print(-1)