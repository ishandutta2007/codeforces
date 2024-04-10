for _ in range(int(input())):
    a, s = input().split()
    i = len(a) - 1
    j = len(s) - 1
    b = []
    pos = True
    while(j >= 0):
        if(j < i):
            pos = False
            break
        if(i < 0):
            b.append(int(s[j]))
            j -= 1
        elif(int(s[j]) >= int(a[i])):
            b.append(int(s[j]) - int(a[i]))
            j -= 1
            i -= 1
        else:
            if(j == 0):
                pos = False
                break
            else:
                b.append(int(s[j - 1])*10 + int(s[j]) - int(a[i]))
                j -= 2
                i -= 1
    for i in b:
        if(int(i) < 0 or int(i) > 9):
            pos = False
            break
    if(pos):
        b.reverse()
        while(int(b[0]) == 0):
            b.pop(0)
        for i in b:
            print(i, end='')
        print()
    else:
        print(-1)