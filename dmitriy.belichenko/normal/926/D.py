
from sys import stdin

arr = [stdin.readline().strip() for i in range(6)]

price = [
    [3, 3, 4, 4, 3, 3],
    [3, 3, 4, 4, 3, 3],
    [2, 2, 3, 3, 2, 2],
    [2, 2, 3, 3, 2, 2],
    [1, 1, 2, 2, 1, 1],
    [1, 1, 2, 2, 1, 1]
]

best = 0
for i in range(6):
    for j in range(2, 4):
        if (arr[i][j + 1] == '.'):
            best = max(best, price[i][j])
    for j in range(0, 2):
        if (arr[i][j] == '.'):           
            best = max(best, price[i][j])
    for j in range(4, 6):     
        if (arr[i][j + 2] == '.'):
            best = max(best, price[i][j])

#print(best)

for i in range(6):
    for j in range(2, 4):
        if (arr[i][j + 1] == '.' and price[i][j] == best):
            arr[i] = arr[i][:j + 1] + 'P' + arr[i][j + 2:]
            print('\n'.join(arr))
            exit(0)
    for j in range(0, 2):
        if (arr[i][j] == '.' and price[i][j] == best):
            arr[i] = arr[i][:j] + 'P' + arr[i][j + 1:]
            print('\n'.join(arr))
            exit(0)
    for j in range(4, 6):
        if (arr[i][j + 2] == '.' and price[i][j] == best):
            arr[i] = arr[i][:j + 2] + 'P' + arr[i][j + 3:]
            print('\n'.join(arr))
            exit(0)