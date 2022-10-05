import sys
input = sys.stdin.readline

def get(i,j):
    print('?',i+1,j+1)
    sys.stdout.flush()
    return int(input())

n = int(input())
out = [n] * n
inds = list(range(n))
while len(inds) >= 2:
    a = inds.pop()
    b = inds.pop()

    r1 = get(a,b)
    r2 = get(b,a)

    if r1 > r2:
        out[a] = r1
        inds.append(b)
    else:
        out[b] = r2
        inds.append(a)

print('!',' '.join(map(str,out)))
sys.stdout.flush()