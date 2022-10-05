from sys import stdout

n, k = map(int, input().split())
l = [str(i + 1) for i in range(k + 1)]
outs = dict()

for i in range(k + 1):
    copy = l[:]
    copy.pop(i)
    print('?', ' '.join(copy))
    stdout.flush()

    ind, val = map(int, input().split())
    if val not in outs:
        outs[val] = 0
    outs[val] += 1

tol = outs[max(outs.keys())]
print('!', tol)
stdout.flush()