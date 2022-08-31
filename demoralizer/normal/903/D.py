n = int(input())
a = list(map(int,input().split()))
f = {}
for x in a:
   f[x] = 0
   f[x+1] = 0
   f[x-1] = 0

ans = 0
for i in range(n):
   ans += (2 * i - n + 1) * a[i]
   f[a[i]] += 1
   ans += f[a[i]+1]
   ans -= f[a[i]-1]
   
print(ans)