program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,i,c: integer;
    a: array[1..100]of integer;
begin
  read(n);
  for i:=1 to n do begin
    read(c);
    a[c]:=i;
  end;
  for i:=1 to n do
    write(a[i],' ');
end.