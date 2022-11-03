{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  a:array[1..5000]of boolean;
  n,ans,t,i:integer;
begin
  readln(n);
  for i:=1 to n do
    a[i]:=false;
  for i:=1 to n do
  begin
    read(t);
    a[t]:=true;
  end;
  ans:=0;
  for i:=1 to n do
    if (not a[i])then
      inc(ans);
  write(ans);
end.