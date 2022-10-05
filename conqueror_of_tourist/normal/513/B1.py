inp = input().split(' ')
n = int(inp[0])
m = bin(int(inp[1])-1)[2:]
lenbin = n-1
while len(m) < lenbin:
    m = '0' + m
start = []
end = []
for x in range(n-1):
    if m[x] == '0':
        start = start + [x+1]
    else:
        end = [x+1] + end
final = start + [n] + end
for x in final:
    print(x, end = ' ')