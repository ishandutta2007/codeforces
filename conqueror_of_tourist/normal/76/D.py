A = int(input())
B = int(input())
x = (A - B)//2
y = x ^ B
if x + y == A and x ^ y == B:
    print(x,y)
else:
    print(-1)