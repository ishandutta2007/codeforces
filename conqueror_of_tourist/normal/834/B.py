n, k = list(map(int,input().split()))
s = input()
start = [-1]*26
end = [-1]*26

for i in range(n):
    door = ord(s[i])-ord('A')
    end[door] = i
    if start[door] == -1:
        start[door] = i

l = []
for i in range(26):
    l.append([i,1,start[i]])
    l.append([i,-1,end[i]])

l = sorted(l,key=lambda x: x[2])

num = 0
m = 0
for i in l:
    num += i[1]
    m = max(m,num)

if m > k:
    print('YES')
else:
    print('NO')