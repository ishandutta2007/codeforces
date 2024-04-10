t = int(input())
for _ in range(t):
    if _:
        input()
    knights = []
    for i in range(8):
        s = input().strip()
        for j in range(8):
            if s[j] == 'K':
                knights.append((i,j))
    n1 = knights[0]
    n2 = knights[1]
    """
    if n1[0] % 2 == n2[0] % 2 and n1[1] % 2 == n2[1] % 2:
        c1 = n1[0]//2 + n1[1]//2
        c2 = n2[1]//2 + n2[0]//2
        if c1 % 2 == c2 % 2:
            print('YES')
        else:
            print('NO')
    """
    if n1[0] % 4 == n2[0] % 4 and n1[1] % 4 == n2[1] % 4:
        print('YES')
    else:
        print('NO')