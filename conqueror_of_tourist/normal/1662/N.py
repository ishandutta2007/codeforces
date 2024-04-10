import sys
input = sys.stdin.readline

n = int(input())

o1 = [0] * (n * n)
o2 = [0] * (n * n)
for i in range(n):
    curr = (list(map(int, input().split())))

    for j in range(n):
        o1[curr[j] - 1] = i
        o2[curr[j] - 1] = j
        

row_count = [0] * n
col_count = [0] * n

ct = 0

for u in range(n * n):
    i = o1[u]
    j = o2[u]

    ct += row_count[i] * col_count[j]

    row_count[i] += 1
    col_count[j] += 1


n2 = (n * n - n)//2

ct -= n2 * n2

print(n2 * n2 - ct)