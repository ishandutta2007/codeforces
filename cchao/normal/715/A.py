n = input()

cur = 2
l = 1

while l <= n:
    g = (l * (l + 1)) ** 2
    print (g - cur) / l
    cur = l * (l + 1)
    l += 1