a, b, c = map(int, input().split())

a += c
b += c

if a > b:a = b+1
if b > a:b = a+1

print(a+b)