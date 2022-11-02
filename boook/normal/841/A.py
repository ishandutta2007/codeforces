n, m = map(int, input().split())
s = input()
print("YES" if max([s.count(i) for i in s]) <= m else "NO")