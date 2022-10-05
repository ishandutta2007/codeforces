t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if a == sorted(a):
        print('NO')
    else:
        print('YES')