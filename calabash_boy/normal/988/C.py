k=int(input());
d = {};
for i in range(1,k+1):
  n = int(input());
  a=list(map(int,input().split(' ')));
  Sum = sum(a);
  for j in range(1,n+1):
    temp = Sum-a[j-1];
    if temp in d:
      print("YES");
      print(i,j);
      print(d[temp][0],d[temp][1]);
      exit();
  for j in range(1,n+1):
    temp = Sum-a[j-1];
    d[temp] = (i,j);
print("NO");