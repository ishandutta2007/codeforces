n = int(input())

s = list(str(input()))

cnt = 0

for i in s:
	if i == 'x':
		cnt += 1

print(int(abs(cnt-n/2)))
if cnt < n/2:
	for i in range(0,n):
		if s[i] == "X" and cnt<n/2:
			s[i] = "x"
			cnt += 1
else:
	for i in range(0,n):
		if s[i]=="x" and cnt>n/2:
			s[i] = "X"
			cnt -= 1

print(''.join(s))