import string

s = raw_input()

ans = 0
for ci in string.ascii_lowercase:
    if ci in s:
        ans += 1

print ans