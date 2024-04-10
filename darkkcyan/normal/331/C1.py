from __future__ import division, print_function

n = int(raw_input())
ans = 0
while n > 0:
    bigd = 0
    t = n
    while t > 0:
        bigd = max(bigd, t % 10)
        t //= 10
    ans += 1
    n -= bigd;
print(ans)