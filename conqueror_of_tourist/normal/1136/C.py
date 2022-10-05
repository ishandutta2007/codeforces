n, m, *_ = list(map(int, input().split()))

b1 = []
for i in range(n):
    b1.append(input().split())

b2 = []
for i in range(n):
    b2.append(input().split())

def works(n, m, b1, b2):
    for diag in range(n + m - 1):
        l1 = []
        l2 = []
        for col in range(diag + 1):
            point = [col, diag-col]
            if 0 <= point[0] < n and 0 <= point[1] < m:
                l1.append(b1[point[0]][point[1]])
                l2.append(b2[point[0]][point[1]])
        if sorted(l1) != sorted(l2):
            return False
    return True

if works(n, m, b1, b2):
    print('YES')
else:
    print('NO')