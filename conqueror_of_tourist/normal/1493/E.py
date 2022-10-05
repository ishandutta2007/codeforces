n = int(input())
l = input().strip()
r = input().strip()

if l[0] == '0' and r[0] == '1':
    print('1'*n)
elif l == r:
    print(l)
elif int(r,2) == int(l,2) + 1:
    print(r)
else:
    out = list(r)
    out[-1] = '1'
    print(''.join(out))