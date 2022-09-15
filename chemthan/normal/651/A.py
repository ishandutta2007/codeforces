a, b = map(int, input().split())
ans = 0
while a > 0 and b > 0:
    ans += 1
    if a > b:
        a -= 2
        b += 1
    else:
        a += 1
        b -= 2
if a < 0 or b < 0:
    ans -= 1
print(ans)