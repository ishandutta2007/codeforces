t = int(input())

p2 = [1]
for i in range(40):
    p2.append(2 * p2[-1])

ff = 'FastestFinger'
a = 'Ashishgup'


def prime(p):
    for i in range(3, min(4 * 10 ** 4,p), 2):
        if p % i == 0:
            return False
    return True

for i in range(t):
    n = int(input())
    if n == 1:
        print(ff)
    elif n == 2:
        print(a)
    elif n in p2:
        print(ff)
    elif (n % 4 != 2):
        print(a)
    else:
        testp = n//2

        if prime(testp):
            print(ff)
        else:
            print(a)