i = input().split(' ')
e = int(i[0])
n = int(i[1])
a = 0
while e > 0 and n > 0 and not(e == 1 and n == 1):
    if e > n:
        e -= 2
        n -= 1
        a += 1
    else:
        e -= 1
        n -= 2
        a += 1
print(a)