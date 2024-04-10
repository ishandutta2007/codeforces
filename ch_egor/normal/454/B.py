n = int(input())
arr = list(map(int,input().split()))
start = 0
for i in range(n -1 ):
	if(arr[i] > arr[i + 1]):
		start = i + 1
		
arr = arr[start:]+arr[:start]
for i in range(n - 1):
	if(arr[i] > arr[i+1]):
		print(-1)
		exit(0)
else:
	print((n - start)%n)