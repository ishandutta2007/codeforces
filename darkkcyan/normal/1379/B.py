for testcase in range(int(input())):
    l, r, m = map(int, input().split())
    
    diff = r - l
    hasans = False
    for a in range(l, r + 1):
        if m % a == 0:
            # print(m // a) 
            print(a, l, l)
            hasans = True
            break
        
        if m // a > 0 and m % a <= diff:
            # print(m // a) 
            print(a, r, r - m % a)
            hasans = True
            break
        if (a - m % a) <= diff:
            # print(m // a + 1) 
            print(a, r - a + m % a, r)
            hasans = True
            break
    assert(hasans)