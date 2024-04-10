n, m = map(int, input().split())
a = [i for i in map(int, input().split()) if i < 0]
print(-sum(sorted(a)[0:min(m, len(a))]))