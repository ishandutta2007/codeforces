n = int(input())
v1 = list(map(int, input().split()))
v2 = list(map(int, input().split()))

if v1[0] < 0:
    v1[0] *= -1
    v1[1] *= -1

if v2[0] < 0:
    v2[0] *= -1
    v2[1] *= -1

while v2[0]:
    sub = v1[0] // v2[0]
    v1[0] -= v2[0] * sub
    v1[1] -= v2[1] * sub

    v1,v2=v2,v1

y = abs(v2[1])
x = abs(v1[0])

if x * y == n:
    print('YES')
    out = []
    for i in range(x):
        for j in range(y):
            out.append(str(i) + ' ' + str(j))
    print('\n'.join(out))
else:
    print('NO')