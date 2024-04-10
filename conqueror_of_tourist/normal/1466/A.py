import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    out = set()
    l = list(map(int, input().split()))
    for v in l:
        for v2 in l:
            out.add(abs(v-v2))
    print(len(out)-1)