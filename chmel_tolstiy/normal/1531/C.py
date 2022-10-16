import sys
from collections import defaultdict


def main():
	n = int(input())
	if n == 2:
		print(-1)
		return

	k = 1
	while k * k < n:
		k += 1


	if n == k * k - 2:
		k += 1

		f = [['.'] * k for _ in range(k)]

		for i in range(k - 1):
			for j in range(k - 1):
				f[i][j] = 'o'
		f[k-2][k-2] = f[k-3][k-2] = f[k-2][k-3] = f[k-3][k-3] = '.'
		f[k-1][0] = f[0][k-1] = 'o'
	elif n == k * k:
		f = [['o'] * k for _ in range(k)]
	else:
		f = [['.'] * k for _ in range(k)]

		for i in range(k - 1):
			for j in range(k - 1):
				f[i][j] = 'o'

		r = n - (k - 1) * (k - 1)
		if r % 2:
			f[k-2][k-2] = '.'
			r += 1
		for i in range(r // 2):
			f[i][k-1] = f[k-1][i] = 'o'

	print(k)
	print("\n".join(["".join(r) for r in reversed(f)]))


if __name__ == '__main__':
	main()