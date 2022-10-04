program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
  n,i:Integer;
  day,min,a,ans:Integer;
  days,p:array[1..100000] of Integer;
begin
  Readln(n);
  day:=0;
  min:=2000000000;
  for i:=1 to n do
  begin
    days[i]:=0;
    p[i]:=0;
  end;
  for i:=1 to n do
  begin
    Readln(a,p[i]);
    if p[i]<min then
    begin
      min:=p[i];
      day:=i;
    end;
    Inc(days[day],a);
  end;
  ans:=0;
  for i:=1 to n do
  begin
    Inc(ans,p[i]*days[i]);
  end;
  Writeln(Ans);
 // Readln(n);
end.