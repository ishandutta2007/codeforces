#!/usr/bin/python3

def fastpow(a, n, mod):
	res = 1;
	
	while (n != 0):
		if (n % 2):
			res = (res * a) % mod
		
		a = (a * a) % mod
		n //= 2
	
	return res


n = int(input())

mod = 1000 * 1000 * 1000 + 7

print ((mod + fastpow(27, n, mod) - fastpow(7, n, mod)) % mod)