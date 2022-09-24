n , s = map(int, input().split())
d = [0] * (n + 1)
cnt = 0
for i in range(0 , n - 1):
    a , b = map(int, input().split())
    d[a - 1] += 1
    d[b - 1] += 1
for i in range(0 , n):
    if(d[i] == 1):
        cnt += 1
print(2.0 * s / cnt)