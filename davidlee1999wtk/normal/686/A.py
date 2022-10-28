n, x = map(int, input().split())
cnt= 0
for i in range(0, n, 1):
    op, d = input().split()
    d = int(d)
    if op == "+":
        x += d
    elif x >= d:
        x -= d
    else:
        cnt += 1
print(str(x)+' '+str(cnt))