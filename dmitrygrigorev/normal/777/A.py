x = int(input())
n = int(input())
st = n
if x % 4 == 1:
    if n == 1:
        st = 0
    if n == 2:
        st = 2
    if n == 0:
        st = 1
if x % 4 == 2:
    if n == 1:
        st = 2
    if n == 2:
        st = 0
    if n == 0:
        st = 1
if x % 4 == 3:
    if n == 1:
        st = 1
    if n == 2:
        st = 0
    if n == 0:
        st = 2
sts = x // 4
if sts % 3 == 0:
    print(st)
if sts % 3 == 1:
    print((st - 1) % 3)
if sts % 3 == 2:
    print((st - 2) % 3)