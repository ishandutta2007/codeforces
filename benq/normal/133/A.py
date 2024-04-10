import sys

p = input()

for i in p:
	if i == 'H' or i == '9' or i == 'Q':
		print("YES")
		sys.exit()

print("NO")