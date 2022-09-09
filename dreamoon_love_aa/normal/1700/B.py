t = int(input())
while t > 0:
    t = t - 1
    n = int(input())
    s = input()
    if s[0] == '9':
        print(int("1"*(n+1))-int(s))
    else:
        print(int("9"*n)-int(s))