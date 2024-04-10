inp = input().split(' ')
a = int(inp[0])
b = int(inp[1])
if (b-a)<2:
    print(-1)
elif (b-a) == 2 and b%2 == 1:
    print(-1)
else:
    if a%2 == 1:
        a = a + 1
    print(a,a+1,a+2)