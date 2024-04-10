t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(lambda x: int(x) - 1, input().split()))

    for i in range(n):
        if l[i] != i:
            break
    else:
        print(0)
        continue

    for j in range(i, n):
        if l[j] == j:
            break
    else:
        print(1)
        continue

    for k in range(j, n):
        if l[k] != k:
            break
    else:
        print(1)
        continue

    print(2)