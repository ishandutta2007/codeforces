n = int(input())
out = 0
mult = 1
while n > 1:
    out += mult * (n//2)
    n -= n//2
    mult *= 2
print(out)