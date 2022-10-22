n, M = map(int, raw_input().split())
field = [map(int, raw_input().split()) for i in range(n)]

def minzero(x):
    m = min(x)
    return [i - m for i in x], m

def ng():
    print -1
    exit()

def solve(field, n, M, Row, Col):
    tmp, _ = minzero(field[0])
    row = []
    for f in field:
        hoge, m = minzero(f)
        if(hoge != tmp):ng()
        row.append(m)

    ans = []
    for i in range(n):
        for j in range(row[i]):
            ans.append("%s %d"%(Row, i+1))
            
    for i in range(M):
        for j in range(tmp[i]):
            ans.append("%s %d"%(Col, i+1))

    return ans

def trans(x):
    m = len(x)
    n = len(x[0])
    return [[x[i][j] for i in range(m)] for j in range(n)]

ans1 = solve(field, n , M, "row", "col")
ans2 = solve(trans(field), M, n, "col", "row")

if len(ans1) < len(ans2):
    ans = ans1
else:
    ans = ans2

print len(ans)
print "\n".join(ans)