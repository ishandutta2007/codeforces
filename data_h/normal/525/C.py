n = input()

lst = map(int, raw_input().split())

lst.sort()

wait = list()

i = n - 1
while i >= 1 :
	if (lst[i] == lst[i - 1]):
		wait.append(lst[i])
		i = i - 2
	elif (lst[i] - 1 == lst[i - 1]) :
		wait.append(lst[i] - 1);
		i = i - 2
	else :
		i = i - 1

i = 0
length = len(wait)
answer = 0
while i + 1 < length:
	answer = answer + wait[i] * wait[i + 1]
	i = i + 2

print answer