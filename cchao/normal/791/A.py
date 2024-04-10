def ris():
    return (int(x) for x in raw_input().split())

(a, b) = ris()
ans = 0

while a <= b:
    (a, b, ans) = (a * 3, b * 2, ans + 1)

print ans