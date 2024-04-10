import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))

    left = [0]
    for i in range(n):
        v = l[i]
        if left[-1] == -1 or v < left[-1]:
            left.append(-1)
        else:
            left.append(v - left[-1])

    right = [0]
    for i in range(n - 1, -1, -1):
        v = l[i]
        if right[-1] == -1 or v < right[-1]:
            right.append(-1)
        else:
            right.append(v - right[-1])
    right.reverse()

    if left[-1] == 0:
        out.append('YES')
        continue

    for i in range(n - 1):
        four = [left[i], l[i+1], l[i], right[i+2]]
        if four[0] >= 0 and four[3] >= 0 and four[1] >= four[0] and four[1] - four[0] == four[2] - four[3]:
            out.append('YES')
            break
    else:
        out.append('NO')

print('\n'.join(out))