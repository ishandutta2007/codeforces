import sys
input = sys.stdin.readline
n = int(input())

primes = []
b = [True] * (n+1)
b[0]=b[1]=False
for i in range(n+1):
	if b[i]:
		primes.append(i)
		for j in range(2*i, n+1,i):
			b[j]=False
			
a = [True] * (n + 1)
a[0] = False
curr = 2
count = n
recent = []
for i in range(n+1):
	while curr <= n and not a[curr]: curr += 1
	if curr <= n:
		print('B',curr)
		for j in range(curr, n+1,curr):
			if a[j]:
				a[j] = False
				count -= 1
		recent.append(curr)
	if len(recent) > 100 or i == n:
		print('A',1)
		sys.stdout.flush()
		for v in recent: input()
		act = int(input())
		if act != count:
			break
		else:
			recent = []
for v in recent:
	print('A',v)
	sys.stdout.flush()
	if int(input()):
		out=v
		for p in primes:
			if p<v:
				continue
			while True:
				if p*out>n:
					break
				print('A',p*out)
				sys.stdout.flush()
				if int(input()):
					out *= p
				else:
					break
		print('C',out)
		break
					
else:
		print('C',1)