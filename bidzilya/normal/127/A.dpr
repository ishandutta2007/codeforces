program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var n,k,i,j: integer;
    ax,ay: array[1..100]of real;
    p: real;
begin
  read(n,k);
  for i:=1 to n do
    read(ax[i],ay[i]);
  p:=0;
  for i:=2 to n do
    p:=p+sqrt(sqr(ax[i]-ax[i-1])+sqr(ay[i]-ay[i-1]));
  p:=p*k/50;
  write(p:0:8);
end.