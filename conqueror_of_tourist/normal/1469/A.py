t=int(input())
for _ in range(t):
    s=input()
    l=r=q=0
    for c in s:
        if c == '(': l += 1
        if c == ')': r += 1
        if c == '?': q += 1
    if (l+r+q)%2:
        print('NO')
        continue
    lq = (l+r+q)//2-l
    if not 0 <= lq <= q:
        print('NO')
        continue
    works = True
    d = 0
    for c in s:
        if c == '(': d += 1
        if c == ')': d -= 1
        if c == '?':
            if lq:
                lq -= 1;d+=1
            else:
                d-=1
        if d < 0:
            print('NO')
            break
    else:
        print('YES')