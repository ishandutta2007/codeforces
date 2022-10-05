import sys
input = sys.stdin.readline

n = int(input())

a = list(map(int, input().split()))
start = a[0]

diffs =[]
for i in range(n-1):
	diffs.append(a[i+1]-a[i])
pos = 0
for v in diffs:
	if v>0:
		pos+=v

final= []

def out(ans):
	final.append((ans+1)//2)
		
out(pos+start)

q = int(input())
for _ in range(q):
	l, r, x = map(int, input().split())
	if l>1:
		if diffs[l-2] >= 0:
			pos -= diffs[l-2]
		diffs[l-2] += x
		if diffs[l-2] >= 0:
			pos += diffs[l-2]	
	else:
		start += x
		
	if r<n:
		if diffs[r-1] >= 0:
			pos -= diffs[r-1]
		diffs[r-1] -= x
		if diffs[r-1] >= 0:
			pos += diffs[r-1]
		
	out(pos+start)
print('\n'.join(map(str,final)))