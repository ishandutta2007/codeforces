s = input().lower()
for i in s:
  if 'a' <= i <= 'z' and not (i in ['a', 'e', 'i', 'o', 'u', 'y']):
    print('.'+i,end='')