t = int(input())
while t:
	s = input()
	if s.endswith("po"):
		print("FILIPINO")
	elif s.endswith("desu") or s.endswith("masu"):
		print("JAPANESE")
	else:
		print("KOREAN")
	t -= 1