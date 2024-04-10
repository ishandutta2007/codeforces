n,m = list(map(int,input().split()))
l = []
up = -1
down = -1
left = -1
right = -1
cout = 0
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == 'B':
            cout += 1
            if up == -1:
                up = i
                down = i
                left = j
                right = j
            else:
                down = i
                left = min(j,left)
                right = max(j,right)
            

side =max(down-up,right-left)+1
if side == 0:
    side = 1
if side >  n or side > m:
    print(-1)
else:
    print(side**2-cout)