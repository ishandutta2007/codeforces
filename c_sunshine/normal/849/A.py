n=int(input())
a=list(map(int,input().split()))
if a[0]%2==1 and a[-1]%2==1 and n%2==1:
  print("Yes")
else:
  print("No")