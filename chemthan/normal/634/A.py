import sys
n = int(input())
a = []
b = []
x = map(int, input().split())
for i in x:
    if i > 0:
        a.append(i)
x = map(int, input().split())
for i in x:
    if i > 0:
        b.append(i)
n = n - 1
for i in range(0, n):
    if b[i] == a[0]:
        for j in range(0, n):
            if a[j] != b[(i + j) % n]:
                print("NO")
                sys.exit(0)
        break
print("YES")