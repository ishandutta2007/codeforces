s=raw_input()
flag=0
for ch in s:
    if ch=='H':
        flag=1
    if ch=='Q':
        flag=1
    if ch=='9':
        flag=1
if flag:
    print "YES"
else:
    print "NO"