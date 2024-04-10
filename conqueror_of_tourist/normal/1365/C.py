n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

diff = [0] * n
out = [0] * n
for i in range(n):
    diff[a[i]-1]+=i
for i in range(n):
    diff[b[i]-1]-=i
for v in diff:
    out[v] += 1
print(max(out))