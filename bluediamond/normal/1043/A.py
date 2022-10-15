[n] = raw_input().split()
n = int (n)
v = []
for i in range (n) :
  v.append(0)
v = raw_input().split()
mx = int (-1)
votes = int (0)
for x in v :
  x = int (x)
  mx = max (mx, x)
  votes += x
while (n * mx - votes <= votes) :
  mx = mx + 1
print mx