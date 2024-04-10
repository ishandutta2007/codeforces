def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
 
for i in range(int(input())):
    a, b = map(int, input().split())
    print('Finite' if gcd(a, b) == 1 else 'Infinite')