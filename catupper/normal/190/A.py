n,m=map(int,raw_input().split())
if m==0:
    print n,n
    exit()

if n==0:
    print 'Impossible'
    exit()


print max(n,m),n+m-1