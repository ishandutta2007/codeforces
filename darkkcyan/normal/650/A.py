from sys import stdin

n = int(stdin.readline())
x, y, xy = [], [], []
for i in range(n):
    u, v = map(int, stdin.readline().split())
    x.append(u)
    y.append(v)
    xy.append((u, v))

def cal_pair(a):
    ans = 0
    a.sort()
    cur = 0
    for last in range(1, len(a)):
        if a[last] == a[cur]:
            continue
        ans += (last - cur) * (last - cur - 1) // 2
        cur = last
    ans += (n - cur) * (n - cur - 1) // 2
    return ans
print(cal_pair(x) + cal_pair(y) - cal_pair(xy))