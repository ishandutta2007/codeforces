n = int(input())
m = n
j = 0
if(n == 3):
    print(1 , 1 , 3)
    exit(0)
for i in range ((m+1)//2):
    print(1)
    j = j + 1
for i in range (min(n - j, (n + 2) // 4)):
    j = j + 1
    print(2)

k = 1
ans = []
while n:
    t = 2 + (n // 2 == n // 3)
    ans += [k] * (n - n // t)
    k *= t
    n //= t
for i in range(j , len(ans)):
    print(ans[i])