program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
var n,i,j: integer;
    a,b,p: array[1..100000]of integer;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do
    p[a[i]]:=b[i];
  for i:=1 to n do
    write(p[i],' ');
end.