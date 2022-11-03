def get_ints():
    return map(int, raw_input().strip().split(' '))

def get_cost(p, t):
    return max(3 * p / 10, p - p / 250 * t)

n, m = get_ints()
ans = 0

while n >= 1 and m >= 1 and n + m >= 3:
    ans += 1
    if m >= n:
        m -= 2
        n -= 1
    else:
        n -= 2
        m -= 1
        
print ans