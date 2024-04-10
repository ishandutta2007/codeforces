import sys
input = sys.stdin.readline

n = int(input())

def MakeSet(x):
     x.parent = x
     x.rank   = 0

def Union(x, y):
     xRoot = Find(x)
     yRoot = Find(y)
     if xRoot.rank > yRoot.rank:
         yRoot.parent = xRoot
     elif xRoot.rank < yRoot.rank:
         xRoot.parent = yRoot
     elif xRoot != yRoot:
         yRoot.parent = xRoot
         xRoot.rank = xRoot.rank + 1

def Find(x):
     if x.parent == x:
        return x
     else:
        x.parent = Find(x.parent)
        return x.parent

class Node:
    def __init__ (self, label):
        self.label = label
    def __str__(self):
        return self.label

used = [0] * 26
nodes = [Node(ch) for ch in range(26)]
[MakeSet(node) for node in nodes] 
  
for _ in range(n):
    s = input().strip()
    prev = -1
    for c in s:
        val = ord(c) - 97
        used[val] = 1
        if prev != -1:
            Union(nodes[prev], nodes[val])
        prev = val

outs = [0] * 26
for node in nodes:
    outs[Find(node).label] += 1

count = 0
for val in outs:
    if val != 0:
        count += 1

print(count + sum(used) - 26)