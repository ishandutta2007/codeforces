import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = map(int, input().split())
    s = set()

    for v in l:
        if v in s:
            s.add(-v)
        else:
            s.add(v)

    out.append(len(s))
print('\n'.join(map(str,out)))