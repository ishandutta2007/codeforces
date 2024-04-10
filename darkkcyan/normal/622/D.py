n = int(input())
even, odd = [], []
for i in range(1, n):
    if (n - i) % 2 == 1:
        odd.append(i)
    else:
        even.append(i)
print(*even, end=' ')
print(n, end=' ')
print(*reversed(even), end=' ')
print(*odd, end=' ')
print(*reversed(odd), end=' ')
print(n)