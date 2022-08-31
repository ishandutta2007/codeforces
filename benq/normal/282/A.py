n=int(input())
x=0
for i in range(n):
	z = input()
	if z[1] == '+':
		x += 1
	else:
		x -= 1

print(x)