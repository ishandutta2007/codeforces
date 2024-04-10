n = int(input())
s = input()
go = 0
out = 0
for i in range(n):
    ss = input()
    if ss[:3] == s:
        go += 1
    if ss[-3:] == s:
        out += 1
if out == go:
    print("home")
else:
    print("contest")