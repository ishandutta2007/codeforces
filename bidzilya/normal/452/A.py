names = ["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]
n = int(raw_input())
s = raw_input()

for t in names:
    if n != len(t):
        continue
    good = True
    for i in xrange(n):
        if s[i] != '.' and s[i] != t[i]:
            good = False
            break
    if good:
        print t
        break