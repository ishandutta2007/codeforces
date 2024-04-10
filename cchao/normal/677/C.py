import string
mod = 10 ** 9 + 7
a = string.digits + string.uppercase + string.lowercase + "-_"
a = map(lambda x: (x[0], 3 ** (6 - bin(x[1]).count('1')) % mod), zip(a, range(64)))

p = [1] * 128
for x in a:
	p[ord(x[0])] = x[1]

ans = 1
for x in raw_input():
	ans = ans * p[ord(x)] % mod

print ans