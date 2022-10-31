from collections import Counter
n, k = map(int, raw_input().split())
c = Counter(raw_input())
print 'YES' if c.most_common(1)[0][1] <= k else 'NO'