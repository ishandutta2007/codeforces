def numline(f = int):
  return map(f, input().split())
    
names = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
t = 0
s = input()
for i in range(len(s)):
  for f in names:
    t += int(s[i:].startswith(f))
if t > 1 or t == 0:
  print("NO")
else:
  print("YES")