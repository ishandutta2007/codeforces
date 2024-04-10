var
  a:Array[1..20,1..20]of int64;
  max:int64;
  n,i,j:longint;
begin

  readln(n);
  for i:=1 to n do a[i,1]:=1;
  for i:=1 to n do a[1,i]:=1;
  for i:=2 to n do
    for j:=2 to n do
      a[i,j]:=a[i-1,j]+a[i,j-1];
  max:=1;
  for i:=1 to n do
    for j:=1 to n do
      if max<a[i,j] then max:=a[i,j];
  writeln(max);

end.