import sys
input = sys.stdin.readline

i_ref = 101
j_ref = 201
k_ref = 230

def query(l, r):
    print('? '+str(l)+' '+str(r))
    sys.stdout.flush()
    return int(input())

def forw(n):
    return (n * (n - 1))//2

def rev(n):
    out = int((2 * n) ** (0.5))+ 1
    assert (out * (out - 1))//2 == n
    return out

t = int(input())
for _ in range(t):
    n = int(input())
    tot = query(1, n)
    
    lo = 2
    hi = n
    #[lo,hi)
    while hi - lo > 1:
        test = (lo + hi)//2
        b = query(1, test)
        if b == 0:
            lo = test + 1
        elif b == tot:
            hi = test
        else:
            break
        
    b2 = query(1, test + 1)

    if b2 == tot:
        test = test - 1
        b2 = b
        b = query(1, test)
        assert b > 0

    diff = b2 - b
    if diff == 0:
        j = test + 1
    elif 2 * b2 == diff * (diff + 1):
        i = test - diff + 1

        lo2 = test + 1
        hi2 = hi
        while hi2 - lo2 > 1:
            test = (lo2 + hi2)//2
            b = query(1, test)
            if b == forw(test - i + 1):
                lo2 = test
            else:
                hi2 = test
        j = hi2
    else:
        j = test - diff + 1
        """
        brev = query(test + 1, n)
        b2rev = query(test, n)
        diff = b2rev - brev
        assert(2 * b2rev == diff * (diff + 1))
        k = test + diff
        
        lo2 = lo
        hi2 = test
        while hi - lo > 1:
            test = (lo2 + hi2)//2
            b = query(test, n)
            if b == forw(test - i + 1):
                lo2 = test + 1
            else b == tot:
                hi2 = test
        """

    j_val = query(1, j)
    left_ct = j_val
    right_ct = tot - j_val
    print('!',j - rev(left_ct), j, j + rev(right_ct) - 1)
    sys.stdout.flush()