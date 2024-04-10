from __future__ import print_function, division
import sys
from itertools import permutations
from operator import itemgetter

def check(p):
    vis = [False for i in p]
    ans = []
    for i in p:
        if vis[i]:
            continue
        g = []
        f = i
        while not vis[f]:
            vis[f] = True
            g.append(f)
            f = p[f]
        g.sort(reverse=True)
        ans.append(g)
    ans.sort(key=itemgetter(0))
    #print(ans, p)
    for u, v in zip(p, [u for i in ans for u in i]):
        if u != v:
            return False
    return True


n, k = map(int, raw_input().split())
#for i in permutations(range(n)):
    #if check(i):
        #print(i)

dp = [1, 2]

for i in xrange(2, n + 1):
    dp.append(dp[i - 1] + dp[i - 2])

i = 1
left = n - 1
while left >= 0:
    if k <= dp[left - 1]:
        print(i, end=' ')
        left -= 1
        i += 1
    else:
        k -= dp[left - 1]
        left -= 2
        print(i + 1, i, end = ' ')
        i += 2