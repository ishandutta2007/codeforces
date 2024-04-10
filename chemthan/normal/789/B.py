b, q, l, m = list(map(int, input().split()))
st = set(map(int, input().split()))
mx = 1000
ans = 0
for i in range(0, 100000):
    if abs(b) > l:
        break
    if b not in st:
        ans = ans + 1
    b *= q
    if ans == mx:
        break
if ans == mx:
    print("inf")
else:
    print(ans)