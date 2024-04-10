t = int(input())
for _ in range(t):
    a,b,c = map(int, input().split())
    g = (10 ** c - 1)//9
    print(g * 10 ** (a-c), g * 10 **(b-c)+g)