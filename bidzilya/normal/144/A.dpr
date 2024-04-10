program tmp_1;

{$APPTYPE CONSOLE}
var a:array[1..100]of integer;
    i,n,min,max,ans:integer;
begin
  readln(n);
  read(a[1]);
  min:=1; max:=1;
  for i:=2 to n do begin
    read(a[i]);
    if (a[i]>a[max])then max:=i;
    if (a[i]<=a[min])then min:=i;
  end;
  ans:=max-1+n-min;
  if (max>min)then dec(ans);
  write(ans);
end.