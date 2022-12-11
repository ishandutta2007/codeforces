n = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

ans = False

for i in range(n):
    if a[a[a[i]]] == i:
        ans = True
        break

print('YES' if ans else 'NO')