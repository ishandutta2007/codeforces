
buf = raw_input()

m = input()
n = len(buf)
answer = [' '] * n

operator = [0] * n

for i in raw_input().split():
	x = int(i)
	operator[x - 1] = operator[x - 1] ^ 1;

rev = 0
for i in range((n + 1) / 2):
	r = n - i - 1
	l = i
	rev = rev ^ operator[i];
	if (rev == 1):
		answer[l] = buf[r]
		answer[r] = buf[l]
	else:
		answer[l] = buf[l]
		answer[r] = buf[r]

print ''.join(answer)