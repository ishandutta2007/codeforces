n = int(input())
posts = [tuple(map(int, input().split())) for _ in range(n)]

buckets = [0] * 4
for x, y in posts:
    i = 0
    if x % 4:
        i += 1
    if y % 4:
        i += 2
    buckets[i] += 1

out = 0
for v in buckets:
    out += (v * (v - 1) * (v - 2)) // 6
    out += (v * (v-1))//2 * (n -v)
print(out)