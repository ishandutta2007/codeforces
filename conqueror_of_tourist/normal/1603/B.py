out = []
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    if x > y:
        out.append(x + y)
    elif 3 * x > y:
        out.append((x+y)//2)
    else:
        diff = y % x
        out.append(y - diff//2)
    #print(out[-1] % x, y % out[-1])

print('\n'.join(map(str, out)))