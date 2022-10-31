n = int(input())
s = input()
for i in range(n - 1):
	if (s[i] > s[i + 1]):
		print(s[:i] + s[i + 1:])
		break;
else:
	print(s[:n - 1])