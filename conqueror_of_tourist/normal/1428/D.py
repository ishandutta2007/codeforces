n = int(input())
a = list(map(int, input().split()))

threes = []
twos = []
out = []
for i in range(n):
    if a[i] == 1:
        if twos:
            p = twos.pop()
            out.append((p, i))
        elif threes:
            p = threes.pop()
            out.append((p,i))
            out.append((i,i))
        else:
            out.append((i,i))
    elif a[i] == 2:
        if threes:
            p = threes.pop()
            out.append((p,i))
            out.append((i,i))
        else:
            out.append((i,i))

        twos.append(i)
    elif a[i] == 3:
        if threes:
            p = threes.pop()
            out.append((p,i))
            out.append((i,i))
        else:
            out.append((i,i))

        threes.append(i)
if twos or threes:
    print(-1)
else:
    print(len(out))
    print('\n'.join(map(lambda x: str(x[0] + 1) + ' ' + str(x[1] + 1), out)))