import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    out = []

    def rev(x):
        assert x % 2 == 1
        out.append(x)
        a[:x] = a[x-1::-1]

    works = True
    for i in range(n):
        if (a[i] ^ i) % 2 == 0:
            print(-1)
            works = False
            break
    if not works:
        continue
            

    for j in range(n//2,0,-1):
        for i in range(2 * j + 1):
            if a[i] == 2 * j + 1:
                rev(i + 1)
                break

        for i in range(2 * j + 1):
            if a[i] == 2 * j:
                rev(i)
                break

        #print(a)
            
        rev(2 * j + 1)

        for i in range(2 * j + 1):
            if a[i] == 2 * j + 1:
                rev(i + 1)
                break

        rev(2 * j + 1)

        #print(a)

    #print(a)
    print(len(out))
    print(' '.join(map(str,out)))