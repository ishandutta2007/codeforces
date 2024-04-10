n = int(input())
out = 0
for i in range(n):
  if sum(list(map(int, input().split()))) >= 2:
    out += 1
print(out)