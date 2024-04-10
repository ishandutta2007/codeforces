a,b,c = list(map(int,input().split()))
boo = b >= a and c >= a
if boo:
    print('Yes')
else:
    print('No')