o=[]
for _ in [0]*int(input()):
    a,b,c=map(int,input().split())
    d,e,f,g,h=map(int,input().split())
    a-=d
    b-=e
    c-=f
    if a < 0 or b < 0:
        o.append('NO')
        continue
    s=min(a,g)
    c-=g-s
    t=min(b,h)
    c-=h-t
    if c >= 0:
        o.append('YES')
    else:
        o.append('NO')
print('\n'.join(o))