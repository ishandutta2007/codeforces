def get_ints():
    return map(int, raw_input().strip().split(' '))

s = raw_input()

rem = 0
for i in xrange(len(s)):
    rem = (rem * 10 + ord(s[i]) - ord('0')) % 4

a = [[1], [1, 2, 4, 3], [1, 3, 4, 2], [1, 4]]

res = 0
for i in xrange(4):
    res = (res + a[i][rem % len(a[i])]) % 5

print res