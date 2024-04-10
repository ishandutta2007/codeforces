a = int(raw_input())
b = int(raw_input())
c = int(raw_input())

print max(a + b + c,
          a + b * c, (a + b) * c,
          a * b + c, a * (b + c),
          a * b * c)