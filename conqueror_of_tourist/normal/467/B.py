def pad(inp,num):
    while len(inp)<num:
        inp = '0' + inp
    return inp

inp = input().split(' ')
players = []
for x in range(int(inp[1])+1):
    players.append(pad(bin(int(input()))[2:],int(inp[0])))
fedor = players.pop()
output = 0
for player in players:
    diff = 0
    for b in range(len(fedor)):
        if fedor[b] != player[b]:
            diff += 1
    if diff <= int(inp[2]):
        output += 1
print(output)