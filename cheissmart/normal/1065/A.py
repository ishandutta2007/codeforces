t = int(input())

for i in range(t):
    l = input().split()
    s = int(l[0])
    a = int(l[1])
    b = int(l[2])
    c = int(l[3])
    ans = s//c;
    ans += ans//a*b
    print(ans)