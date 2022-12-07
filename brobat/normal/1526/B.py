for _ in range(int(input())):
    x = int(input())
    r = x%11
    if(x>=(111*r) or x%11==0):
        print("YES")
    else:
        print("NO")