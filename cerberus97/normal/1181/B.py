l = int(input())
n = input()
best = int(n)
p = (l - 1) // 2
for i in range(p, -1, -1):
	if (n[i + 1] == '0'):
		continue

	best = min(best, int(n[0:(i + 1)]) + int(n[i + 1:]))
	break

p = l // 2
for i in range(p, l):
	if (n[i] == '0'):
		continue

	best = min(best, int(n[0:i]) + int(n[i:]))
	break

print(best)