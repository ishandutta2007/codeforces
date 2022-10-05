import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    w = list(map(int, input().split()))
    if sum(w) == x:
        out.append('NO')
    else:
        out.append('YES')
        st = []
        for i in range(n):
            if w[-1] == x:
                a = w.pop()
                b = w.pop()
                w.append(a)
                w.append(b)
            y = w.pop()
            x -= y
            st.append(y)
        out.append(' '.join(map(str, st)))
print('\n'.join(out))