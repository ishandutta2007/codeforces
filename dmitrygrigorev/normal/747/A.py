import math
n = int(input())
k = math.floor(n ** 0.5)
counter = 2
md = 1
while counter <= k:
    if n % counter == 0:
        md = counter
    counter += 1
print(md, n // md)