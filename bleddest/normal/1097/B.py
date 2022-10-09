a = []
n = 0
ans = False

def rec(d, x):
    global a, n, ans
    if d == n:
        if x % 360 == 0:
            ans = True
    else:
        rec(d + 1, x + a[d])
        rec(d + 1, x - a[d])

n = int(input())
for i in range(n):
    a.append(int(input()))
rec(0, 0)
print('YES' if ans else 'NO')