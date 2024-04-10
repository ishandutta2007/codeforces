import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    input()
    count = [0] * 40
    for v in map(int, input().split()):
        curr = 0
        while v:
            v //= 2
            curr += 1
        count[curr] += 1
    out = 0
    for v in count:
        out += (v * (v-1))//2
    print(out)