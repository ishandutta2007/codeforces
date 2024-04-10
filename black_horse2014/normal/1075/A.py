n = int(input())
buf = input().split()
x, y=int(buf[0]), int(buf[1])
white = max(x - 1, y - 1)
black = max(n - x, n - y)
if (white <= black):
	print("white")
else:
	print("black")