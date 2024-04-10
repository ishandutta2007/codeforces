n,k=map(int,input().split());
d = {};
i=1;
for val in input().split():
  if val in d:
   pass; 
  else:
    d[val] =i;
  i+=1;
if len(d) <k:
  print("NO");
else:
  print("YES");
  i=0;
  for val in d:
    print(d[val],end=' ');
    i+=1;
    if i==k:
      break;