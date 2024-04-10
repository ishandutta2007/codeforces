N, A, R, M = map(int, input().split())
if M > A + R:
    M = A + R
    
h = list(map(int, input().split()))

def calc(final):
    adds = 0
    removes = 0

    for v in h:
        if v > final:
            removes += (v - final)
        else:
            adds += (final - v)

    moves = min(adds, removes)
    return M * moves + A * (adds - moves) + R * (removes - moves)

lo = -1 #Higher than next
hi = 10 ** 9 + 1

while hi - lo > 1:
    test = (lo + hi) // 2

    if calc(test) > calc(test + 1):
        lo = test
    else:
        hi = test

print(calc(hi))