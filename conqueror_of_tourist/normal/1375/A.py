t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    for i in range(n):
        l[i] = abs(l[i]) * (-1)**(i%2)
    print(' '.join(map(str,l)))