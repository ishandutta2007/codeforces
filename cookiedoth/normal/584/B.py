n = int(input())
th = 1
se = 1
i = 1
while i<=3*n:
    th = th*3
    th = th % 1000000007
    i = i+1
i = 1
while i<=n:
    se = se*7
    se = se % 1000000007
    i = i+1
x = th-se
if x<0:
    x = x + 1000000007
print(x)