{$APPTYPE CONSOLE}

var a:array[1..100]of integer;
    i,j,k,n:integer;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  for j:=1 to n do
  for k:=1 to n do
  if (k<>j)and(k<>i)and(j<>i)and(a[i]=a[j]+a[k])then
    begin
      writeln(i,' ',j,' ',k);
      halt;
    end;
  write(-1);
end.