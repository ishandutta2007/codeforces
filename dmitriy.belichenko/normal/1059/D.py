n , l , r = 0 , -100000000, 1000000000
x , y = [] , []
def cal(mid):
    mx = 0
    for i in range(n):
        mx = max (mx ,(x[i] - mid) ** 2 / (2 * y[i]) + (y[i] / 2))
    return mx;
n = int(input())
for i in range(n):
    a , b = map(int , input().split())
    x.append(a) , y.append(b)
for i in range(1 , n):
    if(y[i] * y[0] < 0):
        print(-1)
        exit(0)
    if(y[i] < 0):
        y[i] *= -1
if(y[0] < 0):
    y[0] *= -1
for it in range(100):
    m1 , m2 = l + (r - l) / 3 , r - (r - l) / 3
    v1 , v2 = cal(m1) , cal(m2)
    if(v1 > v2):
        l = m1
    else:
        r = m2
print(cal(m1))