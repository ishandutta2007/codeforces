n, m, k = map(int, raw_input().split(' '))
a = map(int, raw_input().split(' '))
ans = 0
for x in a:
    if x == 1:
        if m == 0:
            ans += 1
        else:
            m -= 1
    else:
        if k == 0 and m == 0:
            ans += 1
        else:
            if k > 0:
                k -= 1
            else:
                m -= 1
print ans