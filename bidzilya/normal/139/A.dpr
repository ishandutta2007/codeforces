{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i,t:integer;
  a:array[1..7]of integer;
begin
  read(n);
  for i:=1 to 7 do
    read(a[i]);
  t:=0;
  while n>0 do
  begin
    inc(t);
    if t>7 then
      t:=1;
    dec(n,a[t]);
  end;
  write(t);
end.