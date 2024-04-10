from sys import exit
def numline(f = int):
    return map(f, input().split())
    
n, k, p = numline()
a = numline()
b = [[], []]
for i in a:
  b[i % 2].append(i)

if (len(b[1]) + k - p) % 2 == 1 or len(b[1]) < k - p:
  print("NO")
  exit(0)

ol = [[] for i in range(p)] + [[b[1][i]] for i in range(k - p)]
cl = 0
for i in range(k - p, len(b[1]), 2):
  ol[cl].append(b[1][i])
  ol[cl].append(b[1][i + 1])
  cl = (cl + 1) % k
for i in b[0]:
  ol[cl].append(i)
  cl = (cl + 1) % k

for i in ol:
  if len(i) > 0:
    continue
  print("NO")
  exit(0)

print("YES")
for i in ol:
  print(" ".join(map(str, [len(i)] + i)))