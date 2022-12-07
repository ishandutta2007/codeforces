tt = input()
for qq in xrange(tt):
  x, y = map(int, raw_input().split())
  print ["YES", "NO"][x - y == 1]