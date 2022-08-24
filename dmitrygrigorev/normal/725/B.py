s = input()
ide = "fedabc"
a = int(s[:-1])
b = s[-1]
moves = (a - 1)
if (a - 1) % 4 > 1:
    moves -= 2
moves += (a - 1) // 4 * 12
if a % 2 == 0:
    moves += 6
for i in range(6):
    if ide[i] == b:
        moves += i + 1
        break
print(moves)