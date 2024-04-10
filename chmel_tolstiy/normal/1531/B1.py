import sys
from collections import defaultdict


def main():
	n = int(input())
	h, w, hw = defaultdict(int), defaultdict(int), defaultdict(int)
	result = 0
	for _ in range(n):
		x, y = map(int, input().split())
		if x > y: x, y = y, x
		result += h[x] + w[x] - hw[(x, x)]
		if x != y:
			result += h[y] + w[y] - hw[(y, y)]
			result -= hw[(x, y)]
		h[x] += 1
		w[y] += 1
		hw[(x, y)] += 1
	print(result)


if __name__ == '__main__':
	main()