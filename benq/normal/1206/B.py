def nextInt():
    return int(input())

def nextInts():
    return map(int,input().split())

n = nextInt()
a = nextInts()

prod = 1
ans = 0
zero = 0

for i in a:
    if i < 0:
        prod *= -1
        ans += -i-1
    elif i > 0:
        ans += i-1
    else:
        zero += 1

if zero == 0:
    if prod == -1:
        ans += 2
else:
    ans += zero

print(ans)