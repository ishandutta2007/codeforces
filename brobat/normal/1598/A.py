for _ in range(int(input())):
    n = int(input())
    s = input()
    t = input()
    pos = True
    for i in range(n):
        if(s[i]=='1' and t[i]=='1'):
            print("NO")
            pos = False
            break
    if(pos):
        print("YES ")