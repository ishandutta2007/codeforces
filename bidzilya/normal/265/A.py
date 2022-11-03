def get_ints():
    return map(int, raw_input().strip().split(' '))

s = raw_input()
t = raw_input()

pos = 0
for i in xrange(len(t)):
    if t[i] == s[pos]:
        pos += 1
        
print pos + 1