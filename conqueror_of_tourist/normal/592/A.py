board = [input(),input(),input(),input(),input(),input(),input(),input()]
b = -99
for i in range(8):
    for j in range(7,-1,-1):
        piece = board[j][i]
        if piece == 'W':
            break
        if piece == 'B':
            b = max(b,j)
            break
b = 7-b
w = 99
for i in range(8):
    for j in range(8):
        piece = board[j][i]
        if piece == 'B':
            break
        if piece == 'W':
            w = min(w,j)
if b < w:
    print('B')
else:
    print('A')