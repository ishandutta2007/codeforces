n,m = list(map(int,input().split()))
linp = list(map(int,input().split()))

l = [0]*101
for i in linp:
    l[i] += 1

test = 100
while test > 0:
    l2 = [i//test for i in l]
    peop = sum(l2)
    if peop >= n:
        break
    else:
        test -= 1

print(test)