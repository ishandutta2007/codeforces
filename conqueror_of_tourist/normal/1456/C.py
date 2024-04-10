import sys
input = sys.stdin.readline

n, k = map(int, input().split())
c = list(map(int, input().split()))

c.sort(reverse = True)

out = 0
curr = 0
size = n
for i in range(n):
    out += curr
    curr += c[i]

poss = [out]

b = k + 1
for i in range(n):
    v = c.pop()
    size -= 1
    curr -= v
    out -= curr

    smol = i // b
    out += smol * v

    poss.append(out + curr * (smol + 1))

print(max(poss))