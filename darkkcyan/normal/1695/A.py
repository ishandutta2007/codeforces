def main():
    for testcase in range(int(input())):
        n, m = map(int, input().split())
        a = [list(map(int, input().split())) for i in range(n)]
        def find_mx_pos():
            mx = max(max(row) for row in a)
            for i in range(n):
                for f in range(m):
                    if a[i][f] == mx:
                        return (i, f)
            assert(False)
        
        mx_r, mx_c = find_mx_pos()
        ans = 0
        for r in (-1, n):
            for c in (-1, m):
                ans = max(ans, abs(mx_r - r) * abs(mx_c - c))
        print(ans)
main()