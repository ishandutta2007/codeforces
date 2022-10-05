n, k = map(int,input().split())
lo = 0#Imposs
hi = 10 ** 9#Poss


l = list(map(int, input().split()))

while hi - lo > 1:
    test = lo + (hi - lo)//2

    odd = 0
    skip = False

    for v in l:
        if skip:
            skip = False
            odd += 1
        else:
            if v <= test:
                odd += 1
                skip = True

    even = 0
    skip = True

    for v in l:
        if skip:
            skip = False
            even += 1
        else:
            if v <= test:
                even += 1
                skip = True

    if odd >= k or even >= k:
        hi = test
    else:
        lo = test

print(hi)