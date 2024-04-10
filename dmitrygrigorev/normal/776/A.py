s1, s2 = list(map(str, input().split()))
l = []
l += [s1, s2]
n = int(input())
for i in range(n):
    s3, s4 = list(map(str, input().split()))
    if s1 == s3:
        s1 = s4
    else:
        s2 = s4
    l += [s1, s2]
for i in range(2 * n + 2):
    if i % 2 == 0:
        print(l[i], l[i + 1])