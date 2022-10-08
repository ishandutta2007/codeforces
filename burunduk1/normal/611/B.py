a = []
for i in range(1,62):
  for j in range(i):
    a.append(int("1" * (i - j) + "0" + "1" * j, base=2))
#print(a)
x,y = map(int, input().split())
print(len(list(filter(lambda d : x <= d and d <= y, a))))