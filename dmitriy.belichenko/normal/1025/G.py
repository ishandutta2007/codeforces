n = int(input())
a = [int(i) for i in input().split()]
b = [0] * (n + 1)
sum = 2 ** (n - 1) - 1
for i in a:
    if(i > 0):
        b[i] = b[i] + 1
for i in b:
    sum = sum - 2 ** i + 1
print(sum % 1000000007)