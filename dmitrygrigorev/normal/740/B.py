n, m = list(map(int, input().split()))
line = list(map(int, input().split()))
answer = 0
for i in range(m):
    a, b = list(map(int, input().split()))
    s = 0
    for j in range(a - 1, b):
        s += line[j]
    if s >= 0:
        answer += s
print(answer)