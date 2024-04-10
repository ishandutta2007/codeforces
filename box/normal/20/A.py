f = input()
while '//' in f:
    f = f.replace('//', '/')
while f != '/' and f[-1] == '/':
    f = f[:-1]
print(f)