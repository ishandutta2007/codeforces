from collections import Counter

c = Counter(raw_input() for i in xrange(input()))
print c.most_common(1)[0][0]