st = input()
for i in range(1, len(st)):
    if st[:i] == st[len(st) - i:] and 2*len(st[:i]) > len(st):
        print("YES", st[:i], sep = '\n', end = '')
        exit(0)
print("NO")