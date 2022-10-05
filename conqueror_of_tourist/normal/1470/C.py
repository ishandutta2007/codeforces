import sys, random

n, k = map(int, input().split())

def query(x):
    print('?',x + 1)
    sys.stdout.flush()
    return int(input())
    
curr = 0
while True:
    if query(curr) < k:
        break
    
    curr += 400 + random.randint(1,100)
    curr %= n
    
lo = 0
hi = (n-1)//2
while hi - lo > 1:
    test = (lo + hi)//2
    q = query((test + curr) % n)
    if q < k:
        lo = test
    else:
        hi = test

fin = (hi + curr) % n
print('!',fin + 1)