n, jt = int(input()), 998244353
ksmii = lambda a, b: ksmii(a, b >> 1)**2 * (a if b & 1 else 1) % jt if b else 1

fib = [0, 1, 1]
for i in range(n):
	fib.append((fib[-1] + fib[-2]) % jt)

print(fib[n] * ksmii(2, jt - n - 1) % jt)