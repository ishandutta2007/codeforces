input()
a, b = 0, 0
l = map(int, input().split(' '))
for v in l:
    a += v // 2
    b += (v - v//2)
    a, b = b, a
 
print(min(a,b))