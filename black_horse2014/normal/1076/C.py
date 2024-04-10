tc = int(input())
for t in range(tc):
	d = int(input())
	if (d < 4 and d > 0):
		print("N")
	else:
		a = (d + (d**2 - 4 * d)**0.5) / 2
		b = (d - (d**2 - 4 * d)**0.5) / 2
		if (a >= 0 and b >= 0):
			print("Y", a, b)
		else:
			print("N")