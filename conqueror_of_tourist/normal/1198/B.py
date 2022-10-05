import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int,input().split()))
lUpd = [0]*n
q = int(input())

payoff = [-1]*q
for query in range(q):
    qnext = list(map(int,input().split()))
    if qnext[0] == 1:
        p = qnext[1] - 1
        x = qnext[2]
        l[p] = x
        lUpd[p] = query
    else:
        x = qnext[1]
        payoff[query] = x

maxPayoff = [-1]*q
best = -1
for i in range(q-1,-1,-1):
    best = max(best,payoff[i])
    maxPayoff[i] = best

out = [max(l[p], maxPayoff[lUpd[p]]) for p in range(n)]
print(' '.join(map(str,out)))