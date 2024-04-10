#!/usr/bin/python3

n = int(input())
a = list(map(int, input().split()))

d = dict()
for i in range(n):
    if a[i] not in d:
        d[a[i]] = (1, -i)
    else:
        d[a[i]] = (d[a[i]][0] + 1, -i)

print(max(d.keys(), key=lambda x: d[x]))