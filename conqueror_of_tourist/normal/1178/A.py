n = int(input())
l = list(map(int,input().split()))
tot = sum(l)

a = l[0]
out = [1]
sumOut = l[0] 
for i in range(2,n+1):
    if l[i-1] * 2 <= a:
        out.append(i)
        sumOut += l[i-1]

if sumOut * 2 > tot:
    print(len(out))
    print(' '.join(map(str,out)))
else:
    print(0)