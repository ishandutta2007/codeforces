n = int(input())
s = input()

count = 0
out = []

for i in range(0, n, 2):
    s2 = s[i:i+2]
    if s2 == 'ab' or s2 == 'ba':
        out.append(s2)
    else:
        count += 1
        out.append('ab')

print(count)
print(''.join(out))