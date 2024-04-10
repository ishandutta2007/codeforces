for i in xrange(input()):
    x = input()
    ans = 0
    while x > 0:
        ans += 1
        if x == 3 or x == 2:
            x = 0
        else:
            x -= 2
    print ans