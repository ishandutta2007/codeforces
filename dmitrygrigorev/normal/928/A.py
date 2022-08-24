def f(c):
	c = c.lower()
	if (c == "o"):
		return "0"
	if (c in "il"):
		return "1"
	return c

def lo(s):
	return "".join([f(c) for c in s])

def main():
	login = lo(input())
	n = int(input())
	arr = [lo(input()) for i in range(n)]
	if login not in arr:
		print("Yes")
	else:
		print("No")

main()