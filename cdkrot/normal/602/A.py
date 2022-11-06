#!/usr/bin/python3

def make_num(lst, bx):
	res = 0
	for elem in lst:
		res *= bx
		res += elem
	return res


n, bx = map(int, input().split())
num1  = make_num(map(int, input().split()), bx)

m, by = map(int, input().split())
num2  = make_num(map(int, input().split()), by)

if num1 < num2:
	print('<')
elif num1 == num2:
	print('=')
else:
	print('>')