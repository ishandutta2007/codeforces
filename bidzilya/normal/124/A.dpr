program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var a,b,n,i,j: integer;

begin
  read(n,a,b);
  j:=0;
  for i:=1 to n do
    if (i-1>=a)and(n-i<=b)then
      inc(j);
  write(j);
end.