n = input();
a = set(map(int,input().split(' ')));
Min = min(a);
Max = max(a);
for i in range(31):
  delta = 1<<i;
  for a1 in a:
    if (a1+delta in a) and (a1+2*delta in a):
      print("3");
      print(a1,a1+delta,a1+delta*2,end=' ');
      exit();
for i in range(31):
  delta = 1<<i;
  for a1 in a:
    if a1+delta in a:
      print("2");
      print(a1,a1+delta,end=' ');
      exit();
print("1");
for a1 in a:
  print(a1);
  exit();