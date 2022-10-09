def count_divisors(f, x):     
    ans = 0
    while f > 0:
        f //= x
        ans += f
    return ans

def count_zeroes(f):
    return min(count_divisors(f, 2), count_divisors(f, 5))

m = int(input())
ans = []
for i in range(1, 500001):
    if count_zeroes(i) == m:
        ans.append(i)

print(len(ans))
print(*ans)