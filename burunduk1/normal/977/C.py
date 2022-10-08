n, k = map(int, input().split())
a = sorted(map(int, input().split()))

# print(n, k)
# print(a)
# a[0] ... a[k-1] <= a[k-1]
if k == 0:
	if a[0] == 1:
		print(-1)
	else:
		print(a[0]-1)
elif k < n and a[k-1]==a[k]:
	print(-1)
else:
	print(a[k-1])