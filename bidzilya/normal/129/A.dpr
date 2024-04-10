program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,i,j,sum: integer;
    a: array[1..100]of integer;

begin
  read(n);
  sum:=0;
  for i:=1 to n do begin
    read(a[i]);
    inc(sum,a[i]);
  end;
  j:=0;
  for i:=1 to n do
    if ((sum-a[i])mod 2=0)then
      inc(j);
  write(j);
end.