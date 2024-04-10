

n = int(input())
no1 = list(input())
no2 = list(input())

# n = 5
# no1 = list("82195")
# no2 = list("64723")

total = 0
for i in range(n):
	a = int(no1[i])
	b = int(no2[i])
	if(a > b):
		total += min(a-b, b+10-a)
	else:
		total += min(b-a, a+10-b)

print(total)