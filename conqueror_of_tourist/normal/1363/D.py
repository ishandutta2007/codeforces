import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    sets = []
    for i in range(k):
        sets.append(list(map(int,input().split())))
        sets[-1].pop(0)

    print("?",n,*range(1,n+1))
    sys.stdout.flush()
    overallMax = int(input())

    lo = 1
    hi = n
    while lo < hi:
        test = (lo + hi)//2

        print("?",test - lo + 1, *range(lo, test + 1))
        sys.stdout.flush()
        res = int(input())

        if res == overallMax:
            hi = test
        else:
            lo = test + 1



    out = ['!']
    
    for l in sets:
        if lo in l:
            nexQ = list(filter(lambda i: i not in l, list(range(1, n + 1))))
            print("?",len(nexQ),*nexQ)
            sys.stdout.flush()
            secondMax = int(input())
            out.append(secondMax)
        else:
            out.append(overallMax)
    print(*out)
    sys.stdout.flush()

    verdict = input().strip()
    if verdict == "Incorrect":
        break