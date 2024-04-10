import itertools

sets = [set() for i in range(13)]

l = list(itertools.combinations(range(13),6))
for i in range(len(l)):
    for v in l[i]:
        sets[v].add(i)

import sys

n = int(input())

answers = []
for i in range(13):
    ask = sets[i]
    out = []
    for v in ask:
        if v < n:
            out.append(v + 1)
    if len(out) > 0:
        print('?',len(out),*out)
        sys.stdout.flush()
        answers.append(int(input()))
    else:
        answers.append(0)

out = [0] * n
for i in range(n):
    for s in range(13):
        if i not in sets[s]:
            out[i] |= answers[s]
print('!',*out)