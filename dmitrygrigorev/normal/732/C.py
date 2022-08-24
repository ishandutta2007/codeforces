b, d, s = list(map(int, input().split()))
har = [max(s - 1, d - 1, b), max(d, b - 1, s - 1), max(d - 1, s, b - 1)]
print(har[0] - b + har[1] - d + har[2] - s)