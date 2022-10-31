n = int(input());
a = [];
for i in range(n):
  a.append(input());
a.sort(key=len);
for i in range(n-1):
  if(a[i] not in a[i+1]):
    print("NO");
    exit();
print("YES");
print ('\n'.join(a));