n = int(input())
m = [0]*4
for i in range(n):
    a, b = map(int, input().split())
    a %= 4
    b %= 4
    if(a==0 and b==0):
        m[0] += 1
    elif(a==0 and b==2):
        m[1] += 1
    elif(a==2 and b==0):
        m[2] += 1
    else:
        m[3] += 1
ans = 0
for i in range(4):
    for j in range(4):
        if(i==j):
            ans += m[i]*(m[i]-1)*(m[i]-2)//6
        else:
            ans += (m[i]*(m[i]-1)//2)*(m[j])
print(ans)