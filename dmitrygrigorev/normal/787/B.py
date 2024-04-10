n, m = list(map(int, input().split()))
ans = "NO"
for i in range(m):
    a = set()
    line = list(map(int, input().split()))
    answer = False
    for j in range(1, len(line)):
        if -line[j] in a:
            answer = True
            break
        a.add(line[j])
    if not answer:
        ans = "YES"
        break
print(ans)