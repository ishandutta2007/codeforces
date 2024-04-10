t = int(input())
for _ in range(t):
    x, y = map(int,input().split())
    a, b = map(int,input().split())
    if b > 2 * a:
        b = 2 * a
    print(max(x,y)*a + min(x,y)*(b-a))