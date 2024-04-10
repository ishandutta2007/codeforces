for _ in range(int(input())):
	input()
	s = [input() for _ in range(8)]
	for y in range(1, 7):
		for x in range(1, 7):
			if s[y][x] == '#' and s[y-1][x-1] == '#' and s[y-1][x+1] == '#':
				print(y + 1, x + 1)