input();a=[[],[],[]]
for i,x in enumerate(input().split(),1):a[int(x)-1]+=[i]
print(min(map(len,a)))
for x in zip(*a):print(*x)