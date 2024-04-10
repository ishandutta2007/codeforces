

t = int(input())
for _ in range(t):
    input()
    for v in map(int, input().split()):
        u = round(v ** 0.5)
        if u * u != v:
            print('YES')
            break
    else:
        print('NO')