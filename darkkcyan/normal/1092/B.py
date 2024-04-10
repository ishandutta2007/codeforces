n = int(input())
a = list(sorted(map(int, input().split())))
print(sum(u - v for u, v in zip(a[1::2], a[0::2])))