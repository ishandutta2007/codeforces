n = int(input())
a, b, c, d = 0, 0, 0, 0
for s, x in zip(input(), map(int, input().split())):
    if(s =='h'):  a = a + x;
    if(s =='a'):  b = min(a ,b + x)
    if(s =='r'):   c = min(b, c + x)
    if(s =='d'):  d = min(c, d + x)
print(d)