n, a, b = list(map(int, input().split()))
line = []
aa = input()
for i in range(n):
    line += [int(aa[i])]
print(0 + (line[a-1] != line[b-1]))