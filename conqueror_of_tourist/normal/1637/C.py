import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    if n == 3:
        if a[1] % 2:
            out.append(-1)
        else:
            out.append(a[1] // 2)
        continue

    a.pop(); a.pop(0)

    if all(v == 1 for v in a):
        out.append(-1)
        continue

    need = sum(a)
    for v in a:
        if v % 2 == 1:
            need += 1


    out.append((need + 1)//2)

print('\n'.join(map(str,out)))