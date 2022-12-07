x, y, z = map(int, input().split())
a, b, c = map(int, input().split())
t1 = x - a
t2 = y - b + t1
t3 = z - c + t2
if(t1 <= 0 and t2 <= 0 and t3 <= 0):
    print("YES")
else:
    print("NO")