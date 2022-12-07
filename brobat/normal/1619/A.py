for _ in range(int(input())):
    s = input()
    n = len(s)
    if(n%2):
        print("NO")
        continue
    a = s[0:n//2]
    b = s[n//2:n]
    if(a==b):
        print("YES")
    else:
        print("NO")