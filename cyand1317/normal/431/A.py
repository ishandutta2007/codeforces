from functools import reduce

a = list(map(int, input().split()))
s = list(map(lambda x: int(x) - 1, input()))
ans = reduce(lambda x, e: x + a[e], s, 0)
print(ans)