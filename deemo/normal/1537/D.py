te = int(input())
a = [0] * 1000
for i in range(1, 1000):
    for x in range(2, i):
        if i % x == 0:
            a[i] |= a[i-x]^1
#print(list(zip(a, range(len(a)))))
while te > 0:
    te -= 1
    n = int(input())
    ans = a[n] if n < len(a) else n%2^1
    if n % 2 == 0:
        for i in range(1, 33, 2):
            if n == 2**i:
                ans = 0
    print("Alice" if ans else "Bob")