from sys import stdin

n, m, h = map(int, stdin.readline().split())

cols = list(map(int, stdin.readline().split()))
rows = list(map(int, stdin.readline().split()))

top = [list(map(int, stdin.readline().split())) for i in range(n)]

ans = [[0 if top[i][f] == 0 else min(rows[i], cols[f]) for f in range(m)] for i in range(n)]
print('\n'.join(map(lambda r: ' '.join(map(str, r)), ans)))