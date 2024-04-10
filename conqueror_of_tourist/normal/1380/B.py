T = int(input())
for _ in range(T):
    s = input().strip()
    rc = 0
    sc = 0
    pc = 0
    for c in s:
        if c == 'R':
            rc += 1
        elif c == 'S':
            sc += 1
        else:
            pc += 1
    if rc == max(rc,sc,pc):
        print('P'*len(s))
    elif sc == max(rc,sc,pc):
        print('R'*len(s))
    else:
        print('S'*len(s))