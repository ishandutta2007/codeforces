t = int(input())
for _ in range(t):
    out = []
    works = True
    n = int(input())
    while n:
        if n == 1:
            out.append(1)
            break
        elif n == 2:
            works = False
            break
        elif n == 3:
            works = False
            break
        elif n == 4:
            out += [3, 1, 4, 2]
            break
        elif n == 5:
            out += [5,2,4,1,3]
            break
        elif n == 7:
            out += [7, 4, 2, 6, 3, 1, 5]
            break
        elif n == 8:
            out += [8, 4, 7, 3, 6, 2, 5, 1]
            break
        elif n == 9:
            out += [9, 7, 4, 2, 6, 8, 5, 1, 3]
            break
        else:
            out.append(n)
            out.append(n - 3)
            out.append(n - 1)
            out.append(n - 4)
            out.append(n - 2)
            n -= 5
    if works:
        print(*out)
    else:
        print(-1)