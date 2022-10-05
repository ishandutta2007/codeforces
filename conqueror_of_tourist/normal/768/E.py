import sys
input = sys.stdin.readline

def large(x):
    for i in range(10, -1, -1):
        if i*(i+1)//2 <= x:
            return i
x = int(input())
l = []
for i in range(x):
    l.append(int(input()))
a = [large(i) for i in range(0, 61)]
lol = 0
for i in l:
    i = a[i]
    lol = lol ^ i
if (lol == 0):
    print("YES")
else:
    print("NO")