def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())
a = get_ints()

ans = [0] * sum(a)
last_pos = 0
for i in xrange(n):
    for j in xrange(a[i]):
        ans[last_pos] = i
        last_pos += 1

m = int(raw_input())
q = get_ints()
for cq in q:
    print ans[cq - 1] + 1