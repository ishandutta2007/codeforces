n = input()
m = input()
mod = 1
while mod <= m and n > 0:
    n -= 1
    mod += mod
print m % mod