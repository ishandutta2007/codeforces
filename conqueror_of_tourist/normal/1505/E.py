h, w = map(int, input().split())
board = [input() for _ in range(h)]

out = 0
cx = 0
cy = 0
if board[0][0] == '*':
    out += 1

while True:
    poss = []
    for i in range(h):
        for j in range(w):
            if board[i][j] == '*' and i >= cx and j >= cy and i + j > cx  +cy:
                poss.append((i+j,i,j))
    if poss:
        _, cx, cy = min(poss)
        out += 1
    else:
        break
print(out)