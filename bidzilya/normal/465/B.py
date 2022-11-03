def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())
a = get_ints()

ans = 0
last = -1
for i in xrange(n):
    if a[i] == 1:
        if last == -1:
            ans += 1
        else:
            if last + 1 == i:
                ans += 1
            else:
                ans += 2
        last = i

print ans