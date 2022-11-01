n = input()
buf = raw_input()
keys = [0] * 500

answer = 0

for i in range(n - 1):
	keys[ord(buf[2 * i])] = keys[ord(buf[2 * i])] + 1
	c = ord(buf[2 * i + 1]) - ord('A') + ord('a')
	if (keys[c] == 0) :
		answer = answer + 1
	else:
		keys[c] = keys[c] - 1

print answer