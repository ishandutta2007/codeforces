t = int(input())
for _ in range(t):
    n1, n2, n3 = map(int, input().split())
    if n2 > 0:
        out = '0'*(n1 + 1)+'1'*(n3 + 1)
        n2 -= 1
        out += '01'*(n2//2)
        if n2 % 2:
            out += '0'
        print(out)
    elif n1 > 0:
        print('0'*(n1 + 1))
    else:
        print('1'*(n3 + 1))