{$APPTYPE CONSOLE}
uses Math;
var
  a:array[1..10000]of integer;
  n,m,k,mn,count:int64;
  i:integer;
begin
  readln(n,m,k);
  count:=n div 2 +1; count:=m div count;
  if (n mod 2=0)then begin write(0); halt; end;
  for i:=1 to n do read(a[i]);
  mn:=k*count;
  for i:=1 to n do
    if (i mod 2=1)and(mn>a[i])then
      mn:=a[i];
  write(mn);
end.