k = int(input())
l = list(map(int, input().split()))

zero = -1
big = -1
first = -1
second = -1
other = -1
for v in l:
    if v == 0:
        zero = 0
    elif v == 100:
        big = 100
    elif v <10:
        first = v
    elif v % 10 == 0:
        second = v
    else:
        other = v

out = []
if zero != -1:
    out.append(0)
if big != -1:
    out.append(big)
if first != -1:
    out.append(first)
if second != -1:
    out.append(second)
if first == -1 and second == -1 and other != -1:
    out.append(other)
print(len(out))
print(' '.join(map(str,out)))