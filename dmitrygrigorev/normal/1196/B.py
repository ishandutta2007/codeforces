import sys
input = sys.stdin.readline

q=int(input())
for i in range(q):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    s=0
    for i in range(n):
        s+=a[i]
    if s%2!=k%2:
        print('NO')
    else:
        co=0
        for i in range(n):
            if a[i]%2==1:
                co+=1
        if co<k-1:
            print('NO')
        else:
            e=[]
            i=0
            while len(e)<k-1 and i<n:
                if a[i]%2==1:
                    e.append(i+1)
                i+=1
            e.append(n)
            print('YES')
            print(*e)