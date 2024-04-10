import collections
ri = lambda: map(int, raw_input().split())
input()
a = collections.deque(ri())
b = [0, 0]
i = 0
while len(a) > 0:
    if a[0] > a[-1]:
        b[i] += a.popleft()
    else:
        b[i] += a.pop()
    i ^= 1
print b[0], b[1]