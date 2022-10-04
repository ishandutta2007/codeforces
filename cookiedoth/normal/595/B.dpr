program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  a,b,c:array[1..100000] of Integer;
  p: Int64;
  n,k,i,num:Integer;
  max,one:Integer;
  f,s,ost,f2:Integer;
begin
  Readln(n,k);
  for i:=1 to (n div k) do
    read(a[i]);
  Readln;
  for i:=1 to (n div k) do
    read(b[i]);
  num:=10;
  for i:=2 to k do
    num:=num*10;
  for i:=1 to (n div k) do
  begin
    max:=((num-1) div a[i])+1;
    s:=(num div 10)*b[i];
    f:=s+(num div 10)-1;
    ost:=(s mod a[i]);
    if ost=0 then f2:=s
    else f2:=s+(a[i]-ost);
    if f2>f then one:=0
    else
    begin
      one:=((f-f2) div a[i])+1;
    end;
    c[i]:=max-one;
  end;
  p:=1;
  for i:=1 to (n div k) do
  begin
    p:=p*c[i];
    p:=(p mod 1000000007);
  end;
  Writeln(p);
end.