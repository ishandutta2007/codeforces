a, b = map(int, raw_input().split(' '))
ans = 0
k = 0
while (a > 0):
    ans += 1
    k += 1
    a -= 1
    if k == b:
        k = 0
        a += 1
print ans