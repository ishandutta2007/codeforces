#!/usr/bin/python3

__import__("sys").setrecursionlimit(10 ** 6)
import threading

threading.stack_size(64 * 1024 * 1024)

def dfs(u, h, par, tr, arr):
    arr[u] = h
    for v in tr[u]:
        if v != par:
            dfs(v, h + 1, u, tr, arr)

def longpathv(tr, v):
    n = len(tr)
    arr = [0] * n
    dfs(v, 0, -1, tr, arr)
    ans = max(range(n), key=lambda x: arr[x])
    return ans, arr[ans]

def longpath(tr):
    return longpathv(tr, longpathv(tr, 0)[0])[1]

def main(tr):
    print(longpath(tr))

n, m = map(int, input().split())
tr = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tr[a].append(b)
    tr[b].append(a)

th = threading.Thread(target=main, args=tuple([tr]))
th.start()