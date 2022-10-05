n,leng = list(map(int,input().split()))
s = input()
l = [0]*27

for c in s:
    l[ord(c)-ord('a')+1] += 1

i = 0
num = 0
out = 0
while i < 27 and num < leng:
    if l[i]:
        out += i
        i += 2
        num += 1
    else:
        i += 1

if num == leng:
    print(out)
else:
    print(-1)