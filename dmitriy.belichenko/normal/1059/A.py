n , s , c = map(int,input().split())
ans = 0
x = 0
for i in range(n):
    p ,q = map(int,input().split())
    ans += ( p - x )//c
    x=p+q
    i+=1
ans += ( s - x) // c
print (ans)