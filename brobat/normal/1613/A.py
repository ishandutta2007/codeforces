for _ in range(int(input())):
    a, b = input().split()
    c, d = input().split()
    b = int(b)
    d = int(d)
    x = min(b, d)
    b -= x
    d -= x
    b = min(b, 7)
    d = min(d, 7)
    for i in range(b):
        a += '0'
    for i in range(d):
        c += '0'
    # print(a, c)
    if(int(a) > int(c)):
        print('>')
    elif(int(a) == int(c)):
        print('=')
    else:
        print('<')