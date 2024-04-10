a = input()
b = a . split()
n=int(b[0])
k=int(b[1])
for i in range(k):
    if n % 10 == 0:
        n = n // 10
    else:
        n -= 1
print(n)