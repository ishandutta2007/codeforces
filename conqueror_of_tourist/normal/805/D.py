s = input()[::-1]
o = 0
b = 0
for i in range(len(s)):
  if s[i] == 'a':
    o = (2*o)%(10**9+7)
  else:
    b+=1
    o+=1
print((o+10**9+7-b)%(10**9+7))