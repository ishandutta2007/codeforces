te = int(input())
while te > 0:
    te -= 1
    a, b, c = map(int, input().split())
    if max(a, b, c) == min(a, b, c):
        print("YES")
    else:
        res = False
        res |= a <= b and (b+b-a) // c * c == (b+b-a)
        res |= b <= c and (2*b - c) // a * a == 2*b-c and 2*b-c > 0
        res |= a <= c and (a+c)%2 == 0 and (a+c)//2 //b * b == (a+c)//2
        if res:
            print("YES")
        else:
            a, c = c, a
            res |= a <= b and (b+b-a) // c * c == (b+b-a)
            res |= b <= c and (2*b - c) // a * a == 2*b-c and 2*b-c > 0
            res |= a <= c and (a+c)%2 == 0 and (a+c)//2 //b * b == (a+c)//2
            if res:
                print("YES")
            else:
                print("NO")