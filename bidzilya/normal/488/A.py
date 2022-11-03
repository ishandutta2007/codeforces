def is_happy(x):
    x = abs(x)
    while x > 0:
        if x % 10 == 8:
            return True
        x /= 10
    return False

a = int(raw_input())
b = 1
while not is_happy(a + b):
    b += 1
print b