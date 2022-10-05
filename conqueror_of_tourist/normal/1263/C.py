t = int(input())

for _ in range(t):
    n = int(input())

    l = [n]
    test = 2
    while n//test != l[-1]:
        l.append(n//test)
        test += 1

    while l[-1] != 0:
        l.append(l[-1] - 1)
        
    print(len(l))
    print(' '.join(map(str,l[::-1])))