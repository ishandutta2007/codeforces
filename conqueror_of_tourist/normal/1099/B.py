n = int(input())

a = b = 1

while a * b < n:
    if a < b:
        a += 1
    else:
        b += 1

print(a+b)