def dels(n):
    c1 = 1
    while n > 1:
        n = n // 2
        c1 = c1 * 2 + 1
    return c1

def recursion(n, l, r):
    if l > r:
        return 0
    if n != 1:
        left_count = dels(n) // 2
        ans = recursion(n // 2, l, min(left_count, r)) + recursion(n // 2, max(left_count + 2, l) - left_count - 1, r - left_count - 1)
        if n % 2 != 0 and left_count + 1 >= l and left_count + 1 <= r:
            ans += 1
        return ans
    else:
        return 1


n, l, r = list(map(int, input().split()))
print(recursion(n, l, r))