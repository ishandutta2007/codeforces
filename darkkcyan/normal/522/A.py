from sys import stdin
n = int(stdin.readline())
cnt = {'POLYCARP': 1}
ans = 1
for i in range(n):
    name1, _, name2 = map(lambda s: s.strip().upper(), stdin.readline().split())
    cnt[name1] = cnt[name2] + 1
    ans = max(ans, cnt[name1])
print(ans)