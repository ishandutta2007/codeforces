n = int(input())
s = input().strip()

def f(i):
    if i >= (1 << n):
        return '', 0
    
    left, lc = f(2 * i + 1)
    right, rc = f(2 * i)
    
    if left == right:
        return s[i - 1] + left + left, lc + rc
    if left < right:
        return s[i - 1] + left + right, lc + rc + 1
    return s[i - 1] + right + left, lc + rc + 1
    
print(pow(2, f(1)[1], 998244353))