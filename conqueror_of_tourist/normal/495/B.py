inp = input().split(' ')
a = int(inp[0])
b = int(inp[1])
diff = a-b
if a == b:
    print('infinity')
elif diff < 0:
    print(0)
else:
    l = []
    out = 1
    for x in range(2,int(diff**(1/2))+1):
        num = 0
        y = diff/x
        while y == int(y):
            num += 1
            diff /= x
            y /= x
        if num != 0:
            l.append([x,num])
            out *= (num + 1)
        if diff < x:
            break
    if diff != 1:
        l.append([int(diff),1])
        out *= 2
    if b == 0:
        print(out)
    else:
        flessb = [1]
        for pair in l:
            newl = []
            for x in flessb:
                y = x
                for exp in range(pair[1]+1):
                    if y<=b:
                        newl.append(y)
                        y *= pair[0]
                    else:
                        break
            flessb = set(newl)
        print(int(out-len(flessb)))