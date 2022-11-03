def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())
a = get_ints()

s = [0, 0]

l = 0
r = n - 1
step = 0
while l <= r:
    if a[l] > a[r]:
        s[step % 2] += a[l]
        l += 1
    else:
        s[step % 2] += a[r]
        r -= 1
    step = 1 - step

print s[0], s[1]