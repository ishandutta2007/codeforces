inp1 = input()
inp2 = input()
inp1 = inp1.split(' ')
n = int(inp1[0])
l = int(inp1[1])
inp2 = inp2.split(' ')
for x in range(len(inp2)):
    inp2[x] = int(inp2[x])
inp2.append(-1 * min(inp2))
inp2 = sorted(inp2)
inp2.append(2*l-max(inp2))
max1 = 0
for x in range(n+1):
    max1 = max(max1,inp2[x+1]-inp2[x])
print(max1/2)