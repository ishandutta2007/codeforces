n = int(input())
w = int(input())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))

if min(l1+l2) <= 1:
    print(-1)
else:
    out = w
    for i in l1+l2:
        out *= i/(i-1)
    print(out-w)