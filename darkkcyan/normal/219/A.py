from __future__ import print_function, division
from collections import Counter
import sys
k = int(raw_input())
cnt = Counter(raw_input())

ans = []
for i in cnt.most_common():
    if i[1] % k != 0:
        print(-1)
        sys.exit(0)
    ans.extend([i[0]] * (i[1] // k))

print(''.join(ans) * k)