import sys

m,n = list(map(int,input().split()))

l = []
done = False

for i in range(n):
    print(1)
    sys.stdout.flush()
    ans = int(input())
    if ans != 0:
        l.append(ans)
    else:
        done = True
        break

if not done:
    i = 0
    left = 2
    right = m

    while True:
        test = (left + right)//2
        print(test)
        sys.stdout.flush()
        ans = int(input())*l[i%n]
        if ans == 0:
            break
        else:
            if ans == 1:
                left = test + 1
            else:
                right = test - 1
            i += 1