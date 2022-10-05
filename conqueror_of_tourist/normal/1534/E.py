import sys
input = sys.stdin.readline

n, k = map(int, input().split())

if n % 2  == 1 and k % 2 == 0:
    print(-1)
    exit()

want = [1] * n
tot = n

curr = 0
while tot % k != 0 or want[0] * k > tot:
    want[curr] += 2
    tot += 2
    curr = (curr + 1) % n

out = 0
while tot:
    poss = [(want[i], i) for i in range(n)]
    poss.sort(reverse = True)
    quer = []
    for j in range(k):
        quer.append(poss[j][1] + 1)
        want[poss[j][1]] -= 1
    tot -= k
    print('?',' '.join(map(str,quer)))
    sys.stdout.flush()
    out ^= int(input())
print('!', out)