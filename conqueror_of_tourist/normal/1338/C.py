import sys
input = sys.stdin.readline
out = []

t = int(input())
for _ in range(t):
    n = int(input())
    n -= 1
    rem = n % 3
    n //= 3
    
    s = []
    if n:
        n -= 1
        while n >= 0:
            s.append([['00','00','00'],['01','10','11'],['10','11','01'],['11','01','10']][n % 4][rem])
            n //= 4
            n -= 1

    s.append(['1','10','11'][rem])

    s.reverse()

    out.append(int(''.join(s),2))
print('\n'.join(map(str,out)))