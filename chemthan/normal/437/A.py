a = len(str(input())[2:])
b = len(str(input())[2:])
c = len(str(input())[2:])
d = len(str(input())[2:])
cnt = 0
ans = "C"
if 2 * a <= min(b, c, d) or a >= 2 * max(b, c, d):
    cnt += 1
    ans = "A"
if 2 * b <= min(a, c, d) or b >= 2 * max(a, c, d):
    cnt += 1
    ans = "B"
if 2 * c <= min(a, b, d) or c >= 2 * max(a, b, d):
    cnt += 1
    ans = "C"
if 2 * d <= min(a, b, c) or d >= 2 * max(a, b, c):
    cnt += 1
    ans = "D"
if cnt > 1:
    ans = "C"
print(ans)