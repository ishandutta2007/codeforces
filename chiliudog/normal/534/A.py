n=int(input())
if (n<=2):
	print('1\n1')
	exit()
if (n==3):
	print('2\n1 3')
	exit()
ans=[];print(n);
for i in range(n//2):
	ans.append(str(i+1))
	ans.append(str(n-(i+1)+1))
if (n%2):
	print(' '.join([str(n//2+1)]+ans))
else:
	print(' '.join([str(n//2+1)]+ans[:n-1]))