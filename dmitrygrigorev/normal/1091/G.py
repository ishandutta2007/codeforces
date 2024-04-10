import math
import random
import sys

def interactor(kek):
    return int(sys.stdin.readline())

n = int(sys.stdin.readline())
a = []
while len(a) < 20:
    kek = random.randint(1, n-1)
    if math.gcd(kek, n) != 1:
        continue
    sys.stdout.write(f'sqrt {(kek*kek)%n}\n')
    sys.stdout.flush()
    result = interactor((kek*kek)%n)
    if (result+kek)%n==0:
        continue
    if (result-kek)%n==0:
        continue
    b = int((result+kek)%n)
    c = int((result-kek)%n)
    a += [[b, c]]
e = set()
e.add(n)
for i in range(len(a)):
    ee = set()
    for element in e:
        ee.add(math.gcd(element, a[i][0]))
        ee.add(math.gcd(element, a[i][1]))
    e = ee
result = "! "
kok = []
for element in e:
    kok += [element]
kok = sorted(kok)
sz = len(kok)
if kok[0] == 1:
    sz -= 1
result += str(sz) + " "
for i in range(len(kok)):
    if kok[i] == 1:
        continue
    if i != len(kok)-1:
        result += str(kok[i]) + " "
    else:
        result += str(kok[i])
sys.stdout.write(result)