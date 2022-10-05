from math import log, log10

n = input()

l = list(map(int, input().split()))


def wp(ra, rb):
    return 1/(1 + pow(10, (rb - ra)/400))

lo = 0
hi = 10000
for i in range(300):
    t = (lo + hi)/2

    p = 1
    for v in l:
        p *= wp(t, v)

    #print(t, p)

    rat = log(1/p - 1)/log(10) * 400 + t

    if rat > t:
        lo = t
    else:
        hi = t

def getWinProbability(ra,rb):
    return 1.0 / (1.0 + pow( 10.0, (rb - ra) / 400.0))

def aggregateRatings(teamRatings):
    if(len(teamRatings)==0):
        return 0

    left = 1
    right = 1E4

    for tt in range(100):
        r = (left + right) / 2.0

        rWinsProbability = 1.0
        for i in range (len(teamRatings)):
            rWinsProbability *= getWinProbability(r, teamRatings[i])

        rating = log10(1 / (rWinsProbability) - 1) * 400 + r

        if (rating > r):
            left = r
        else:
            right = r

    return (left + right) / 2.0

print(sum(l))