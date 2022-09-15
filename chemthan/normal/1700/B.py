line = lambda: list(int(x) for x in input().split())
test, = line()

for _ in range(test):
  n, = line()
  d, = line()
  if str(d)[0] == '9':
    print(10**n + int('2' * (n - 1) + '0') + 1 - d)
  else:
    print(10**n - 1 - d)