t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    mi, m1=s, 1
    for i in range(2,n+1):
        s1='' 
        if (n-i)%2==0:
            s1=s[i-1:]+s[:i-1][::-1]
        else:
            s1=s[i-1:]+s[:i-1]
        if s1<mi:
            mi, m1=s1, i
    print(mi) 
    print(m1)