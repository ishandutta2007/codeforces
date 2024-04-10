t=int(input())
for _ in range(t):
    n,k = map(int,input().split())
    if k>(n-1)//2:
        print(-1)
    else:
        odd = list(range(1,k+2))
        even = list(range(k+2,2*k+2))
        out = []
        for i in range(2*k+1):
            if i % 2 == 0:
                out.append(odd[i//2])
            else:
                out.append(even[i//2])
        for i in range(2*k+2,n+1):
            out.append(i)
        print(' '.join(map(str,out)))