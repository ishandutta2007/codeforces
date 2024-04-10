def code(c):
    return ord(c) - ord('a')

def main():
    a = input()
    b = input()
    m = int(input())
    n = 26
    d = [[10 ** 9 for i in range(n)] for j in range(n)]
    for i in range(n):
        d[i][i] = 0
    for i in range(m):
        s, t, w = input().split()
        w = int(w)
        s = code(s)
        t = code(t)              
        d[s][t] = min(d[s][t], w)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])

    if len(a) != len(b):
        print(-1)
    else:
        ans = 0
        res = []
        for i in range(len(a)):
            x = code(a[i])
            y = code(b[i])
            min_c = 'a'
            min_cost = 10 ** 9
            for j in range(n):
                cur = d[x][j] + d[y][j]
                if cur < min_cost:
                    min_cost = cur
                    min_c = chr(j + ord('a'))
            res.append(min_c)
            ans += min_cost
        if ans >= 10 ** 9:
            print(-1)
        else:
            print(ans)
            for j in res:
                print(j, end='')
            print()

main()