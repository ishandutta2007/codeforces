n, s = map(int, raw_input().split())
a = [0] * 204800
r = 0
for i in map(int, raw_input().split()):
    r += a[i ^ s]
    a[i] += 1
print r