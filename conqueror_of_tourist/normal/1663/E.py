import random

n = int(input())

w = 'theseus'

good = True
board = []
for _ in range(n):
    board.append(input().strip())

for s in board:
    pass
    #if w in s:
    #    good = False
    #if w in s[::-1]:
    #    good = False

for i in range(n):
    t = ''.join(board[j][i] for j in range(n))
    #if w in t:
    #    good = False
    #if w in t[::-1]:
    #    good = False

for s in range(2 * n - 2):
    l = []
    for i in range(n):
        if 0 <= s - i < n:
            l.append(board[i][s-i])
    t = ''.join(l)
    #if w in t:
    #    good = False
    #if w in t[::-1]:
    #    good = False

for s in range(-2 * n, 2 * n - 2):
    l = []
    for i in range(n):
        if 0 <= s + i < n:
            l.append(board[i][s+i])
    t = ''.join(l)
    if w in t:
        good = False
    if w in t[::-1]:
        good = False


'''
best = [[-1] * n for _ in range(n)]

for c in range(8):
    for i in range(n):
        for j in range(n):
            if board[i][j] != w[c]:
                continue
            
            for d in range(8):
                ii = i + [0,0,-1,1,1,1,-1,-1][d]
                jj = j + [1,-1,0,0,1,-1,1,-1][d]

                if 0 <= ii < n and 0 <= jj < n:
                    if best[ii][jj] == c - 1:
                        best[i][j] = c
                        if c == 7:
                            good = False
'''

if good:
    print('NO')
else:
    print('YES')