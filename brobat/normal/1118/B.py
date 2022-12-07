n = int(input())
arr = list(map(int, input().split()))
if(n==1):
    print(1)
    exit()
o = [arr[0], arr[0]]
e = [0, arr[1]]
for i in range(2, n):
    if(i%2==0):
        o.append(arr[i] + o[i-1])
        e.append(e[i-1])
    else:
        e.append(arr[i] + e[i-1])
        o.append(o[i-1])
ans = 0
for i in range(n):
    s1 = 0
    s2 = 0
    if(i!=0):
        s1 = o[i-1]
        s2 = e[i-1]
    s1 += e[n-1] - e[i]
    s2 += o[n-1] - o[i]
    if(s1==s2):
        ans += 1
print(ans)