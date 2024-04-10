import sys
A = list(map(int, input().split()))
n = A[0]
n1 = n
l = A[1]
r = A[2]
L = []
X = []
if (n == 0):
    print(0)
    sys.exit()
while (n > 0):
    L.append(n % 2)
    n = n//2
near = 1
ans = 0
for i in range(l, r+1):
    b = -1
    k = i
    d = 1
    f = 0
    while ((k % d) == 0):
        d *= 2
        f += 1
    d /= 2
    f -= 1
    if (L[len(L) - f - 1] == 1): ans += 1
print(ans)