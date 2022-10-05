n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
if n == 1:
    if A[0] == B[0]:
        print("SMALL")
        print(0)
        print()
    else:
        print("IMPOSSIBLE")
elif n == 2:
    out = []
    prefCount = 0
    works  = True
    while (B[0] + B[1] > A[0] + A[1]) and B[0] and B[1]:
        if B[1] < B[0]:
            B[0], B[1] = B[1], B[0]
            out.append(('R',1))

        lim1 = B[1] // B[0]
        lim2 = (B[0] + B[1] - A[0] - A[1]) // B[0]
        do = min(lim1, lim2)
        if do == 0:
            do = 1
        B[1] -= do * B[0]
        out.append(('P',do))
        prefCount += do

    if A == B:
        pass
    elif A == B[::-1]:
        out.append(('R',1))
    else:
        works = False

    if works:
        if prefCount > 2 * 10 ** 5:
            print('BIG')
            print(prefCount)
        else:
            print('SMALL')
            out = list(map(lambda x: x[0] * x[1], out))
            outS = ''.join(out[::-1])
            print(len(outS))
            print(outS)
    else:
        print('IMPOSSIBLE')
        
else:
    out = []
    prefCount = 0
    flipped = False
    works = True
    while (B[0] + B[-1] > A[0] + A[-1]) and works:
        if B[0] < B[-1]:
            for i in range(n - 1, 0, -1):
                if B[i] <= B[i - 1]:
                    works = False
                    break
                else:
                    B[i] -= B[i - 1]
            if flipped:
                out.append('R')
                flipped = False
            out.append('P')
            prefCount += 1
        else:
            for i in range(n - 1):
                if B[i] <= B[i + 1]:
                    works = False
                    break
                else:
                    B[i] -= B[i + 1]
            if not flipped:
                out.append('R')
                flipped = True
            out.append('P')
            prefCount += 1

    if flipped:
        B = B[::-1]
    
    if A == B:
        pass
    elif A == B[::-1]:
        out.append('R')
    else:
        works = False

    if works:
        if prefCount > 2  * 10 ** 5:
            print('BIG')
            print(prefCount)
        else:
            print('SMALL')
            print(len(out))
            print(''.join(out[::-1]))
    else:
        print('IMPOSSIBLE')